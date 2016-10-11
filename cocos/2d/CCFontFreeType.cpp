/****************************************************************************
Copyright (c) 2013      Zynga Inc.
Copyright (c) 2013-2016 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "2d/CCFontFreeType.h"
#include FT_BBOX_H
#include "edtaa3func.h"
#include "2d/CCFontAtlas.h"
#include "base/CCDirector.h"
#include "base/ccUTF8.h"
#include "platform/CCFileUtils.h"



#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32 && CC_TARGET_PLATFORM != CC_PLATFORM_WINRT && CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
#include <iconv.h>
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#endif


namespace  {
    const int CacheTextureWidth = 512;
    const int CacheTextureHeight = 512;
    const int DistanceMapSpread = 3;
    
    FT_Library _FTlibrary = nullptr;
    bool _FTInitialized = false;
    
    
    const char* _glyphASCII = "\"!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþ ";
    const char* _glyphNEHE = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ";
    
    typedef struct _DataRef
    {
        cocos2d::Data data;
        unsigned int referenceCount;
    }DataRef;
    
    static std::unordered_map<std::string, DataRef> s_cacheFontData;
}

NS_CC_BEGIN

bool FontFreeType::initFreeType()
{
    if (!_FTInitialized)
    {
        // begin freetype
        if (FT_Init_FreeType( &_FTlibrary ))
            return false;
        
        _FTInitialized = true;
    }
    
    return  _FTInitialized;
}

void FontFreeType::shutdownFreeType()
{
    if (_FTInitialized == true)
    {
        FT_Done_FreeType(_FTlibrary);
        s_cacheFontData.clear();
        _FTInitialized = false;
    }
}

FontFreeType::FontFreeType()
: _fontRef(nullptr)
, _stroker(nullptr)
, _fontSize(0.0f)
, _distanceFieldEnabled(false)
, _outlineSize(0.0f)
, _lineHeight(0)
, _encoding(FT_ENCODING_UNICODE)
, _usedGlyphs(GlyphCollection::ASCII)
, _iconv(nullptr)
, _currentPage(0)
, _currentPageOrigX(0)
, _currentPageOrigY(0)
, _letterEdgeExtend(2)
, _letterPadding(0)
, _currentPageData(nullptr)
, _fontAscender(0)
, _currLineHeight(0)
{
    initFreeType();
}

FontFreeType::~FontFreeType()
{
    if (_FTInitialized)
    {
        if (_stroker)
        {
            FT_Stroker_Done(_stroker);
        }
        if (_fontRef)
        {
            FT_Done_Face(_fontRef);
        }
    }
    
    s_cacheFontData[_fontName].referenceCount -= 1;
    if (s_cacheFontData[_fontName].referenceCount == 0)
    {
        s_cacheFontData.erase(_fontName);
    }
    
#if CC_ENABLE_CACHE_TEXTURE_DATA
    if (_rendererRecreatedListener)
    {
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();
        eventDispatcher->removeEventListener(_rendererRecreatedListener);
        _rendererRecreatedListener = nullptr;
    }
#endif
    
    delete []_currentPageData;
    
#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32 && CC_TARGET_PLATFORM != CC_PLATFORM_WINRT && CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
    if (_iconv)
    {
        iconv_close(_iconv);
        _iconv = nullptr;
    }
#endif
}

bool FontFreeType::initWithFontFreeTypeConfig(const std::string &fontName, float fontSize, GlyphCollection glyphs,
                        const char *customGlyphs, bool distanceFieldEnabled,int outline)
{
    _fontName = fontName;
    _fontSize = fontSize;
    
    bool succeed = false;
    Texture2D* texture = nullptr;
    
    do
    {
        if (outline > 0)
        {
            _outlineSize = outline * CC_CONTENT_SCALE_FACTOR();
            FT_Stroker_New(_FTlibrary, &_stroker);
            FT_Stroker_Set(_stroker,
                           (int)(_outlineSize * 64),
                           FT_STROKER_LINECAP_ROUND,
                           FT_STROKER_LINEJOIN_ROUND,
                           0);
        }
        
        setGlyphCollection(glyphs, customGlyphs);
        
        if (!createFontObject())
        {
            break;
        }
        
        _fontAscender = getFontAscender();
        
        if (isDistanceFieldEnabled())
        {
            _letterPadding += 2 * DistanceMapSpread;
        }
        
        _currentPageDataSize = CacheTextureWidth * CacheTextureHeight;
        auto outlineSize = getOutlineSize();
        if (outlineSize > 0)
        {
            _lineHeight += 2 * outlineSize;
            _currentPageDataSize *= 2;
        }

        auto pixelFormat = _outlineSize > 0 ? Texture2D::PixelFormat::AI88 : Texture2D::PixelFormat::A8;
        
        texture = new (std::nothrow) Texture2D();
        if (texture == nullptr)
            break;
        
        _currentPageData = new (std::nothrow) unsigned char[_currentPageDataSize];
        memset(_currentPageData, 0, _currentPageDataSize);
        
        if (!texture->initWithData(_currentPageData, _currentPageDataSize, pixelFormat,
                                   CacheTextureWidth, CacheTextureHeight, Size(CacheTextureWidth,CacheTextureHeight) ))
        {
            break;
        }
        
        setTexture(texture, 0);
        texture->release();
        
        if (_usedGlyphs != GlyphCollection::DYNAMIC)
        {
            std::u16string utf16;
            if (StringUtils::UTF8ToUTF16(getGlyphCollection(), utf16))
            {
                updateFontAtlas(utf16);
            }
        }
        
        succeed = true;
        
    } while(false);
    
    if (!succeed)
    {
        CC_SAFE_RELEASE_NULL(texture);
    }
    
    return true;
}

bool FontFreeType::createFontObject()
{
    FT_Face face;
    // save font name locally
    
    auto it = s_cacheFontData.find(_fontName);
    if (it != s_cacheFontData.end())
    {
        (*it).second.referenceCount += 1;
    }
    else
    {
        s_cacheFontData[_fontName].referenceCount = 1;
        s_cacheFontData[_fontName].data = FileUtils::getInstance()->getDataFromFile(_fontName);

        if (s_cacheFontData[_fontName].data.isNull())
        {
            return false;
        }
    }

    if (FT_New_Memory_Face(_FTlibrary, s_cacheFontData[_fontName].data.getBytes(), s_cacheFontData[_fontName].data.getSize(), 0, &face ))
        return false;

    if (FT_Select_Charmap(face, FT_ENCODING_UNICODE))
    {
        int foundIndex = -1;
        for (int charmapIndex = 0; charmapIndex < face->num_charmaps; charmapIndex++)
        {
            if (face->charmaps[charmapIndex]->encoding != FT_ENCODING_NONE)
            {
                foundIndex = charmapIndex;
                break;
            }
        }

        if (foundIndex == -1)
        {
            return false;
        }

        _encoding = face->charmaps[foundIndex]->encoding;
        if (FT_Select_Charmap(face, _encoding))
        {
            return false;
        }
    }

    // set the requested font size
    int dpi = 72;
    int fontSizePoints = (int)(64.f * _fontSize * CC_CONTENT_SCALE_FACTOR());
    if (FT_Set_Char_Size(face, fontSizePoints, fontSizePoints, dpi, dpi))
        return false;
    
    // store the face globally
    _fontRef = face;
    _lineHeight = static_cast<int>(_fontRef->size->metrics.height >> 6);
    
    // done and good
    return true;
}

int * FontFreeType::getHorizontalKerningForTextUTF16(const std::u16string& text, int &outNumLetters) const
{
    if (!_fontRef)
        return nullptr;
    
    outNumLetters = static_cast<int>(text.length());

    if (!outNumLetters)
        return nullptr;
    
    int *sizes = new (std::nothrow) int[outNumLetters];
    if (!sizes)
        return nullptr;
    memset(sizes,0,outNumLetters * sizeof(int));

    bool hasKerning = FT_HAS_KERNING( _fontRef ) != 0;
    if (hasKerning)
    {
        for (int c = 1; c < outNumLetters; ++c)
        {
            sizes[c] = getHorizontalKerningForChars(text[c-1], text[c]);
        }
    }
    
    return sizes;
}

int  FontFreeType::getHorizontalKerningForChars(unsigned short firstChar, unsigned short secondChar) const
{
    // get the ID to the char we need
    int glyphIndex1 = FT_Get_Char_Index(_fontRef, firstChar);
    
    if (!glyphIndex1)
        return 0;
    
    // get the ID to the char we need
    int glyphIndex2 = FT_Get_Char_Index(_fontRef, secondChar);
    
    if (!glyphIndex2)
        return 0;
    
    FT_Vector kerning;
    
    if (FT_Get_Kerning( _fontRef, glyphIndex1, glyphIndex2,  FT_KERNING_DEFAULT,  &kerning))
        return 0;
    
    return (static_cast<int>(kerning.x >> 6));
}

int FontFreeType::getFontAscender() const
{
    return (static_cast<int>(_fontRef->size->metrics.ascender >> 6));
}

const char* FontFreeType::getFontFamily() const
{
    if (!_fontRef)
        return nullptr;

    return _fontRef->family_name;
}

unsigned char* FontFreeType::getGlyphBitmap(unsigned short theChar, long &outWidth, long &outHeight, Rect &outRect,int &xAdvance)
{
    bool invalidChar = true;
    unsigned char* ret = nullptr;

    do
    {
        if (_fontRef == nullptr)
            break;

        if (_distanceFieldEnabled)
        {
            if (FT_Load_Char(_fontRef, theChar, FT_LOAD_RENDER | FT_LOAD_NO_HINTING | FT_LOAD_NO_AUTOHINT))
                break;
        }
        else
        {
            if (FT_Load_Char(_fontRef, theChar, FT_LOAD_RENDER | FT_LOAD_NO_AUTOHINT))
                break;
        }

        auto& metrics = _fontRef->glyph->metrics;
        outRect.origin.x = metrics.horiBearingX >> 6;
        outRect.origin.y = -(metrics.horiBearingY >> 6);
        outRect.size.width = (metrics.width >> 6);
        outRect.size.height = (metrics.height >> 6);

        xAdvance = (static_cast<int>(_fontRef->glyph->metrics.horiAdvance >> 6));

        outWidth  = _fontRef->glyph->bitmap.width;
        outHeight = _fontRef->glyph->bitmap.rows;
        ret = _fontRef->glyph->bitmap.buffer;

        if (_outlineSize > 0 && outWidth > 0 && outHeight > 0)
        {
            auto copyBitmap = new (std::nothrow) unsigned char[outWidth * outHeight];
            memcpy(copyBitmap,ret,outWidth * outHeight * sizeof(unsigned char));

            FT_BBox bbox;
            auto outlineBitmap = getGlyphBitmapWithOutline(theChar,bbox);
            if(outlineBitmap == nullptr)
            {
                ret = nullptr;
                delete [] copyBitmap;
                break;
            }

            long glyphMinX = outRect.origin.x;
            long glyphMaxX = outRect.origin.x + outWidth;
            long glyphMinY = -outHeight - outRect.origin.y;
            long glyphMaxY = -outRect.origin.y;

            auto outlineMinX = bbox.xMin >> 6;
            auto outlineMaxX = bbox.xMax >> 6;
            auto outlineMinY = bbox.yMin >> 6;
            auto outlineMaxY = bbox.yMax >> 6;
            auto outlineWidth = outlineMaxX - outlineMinX;
            auto outlineHeight = outlineMaxY - outlineMinY;

            auto blendImageMinX = MIN(outlineMinX, glyphMinX);
            auto blendImageMaxY = MAX(outlineMaxY, glyphMaxY);
            auto blendWidth = MAX(outlineMaxX, glyphMaxX) - blendImageMinX;
            auto blendHeight = blendImageMaxY - MIN(outlineMinY, glyphMinY);

            outRect.origin.x = blendImageMinX;
            outRect.origin.y = -blendImageMaxY + _outlineSize;

            long index, index2;
            auto blendImage = new (std::nothrow) unsigned char[blendWidth * blendHeight * 2];
            memset(blendImage, 0, blendWidth * blendHeight * 2);

            auto px = outlineMinX - blendImageMinX;
            auto py = blendImageMaxY - outlineMaxY;
            for (int x = 0; x < outlineWidth; ++x)
            {
                for (int y = 0; y < outlineHeight; ++y)
                {
                    index = px + x + ((py + y) * blendWidth);
                    index2 = x + (y * outlineWidth);
                    blendImage[2 * index] = outlineBitmap[index2];
                }
            }

            px = glyphMinX - blendImageMinX;
            py = blendImageMaxY - glyphMaxY;
            for (int x = 0; x < outWidth; ++x)
            {
                for (int y = 0; y < outHeight; ++y)
                {
                    index = px + x + ((y + py) * blendWidth);
                    index2 = x + (y * outWidth);
                    blendImage[2 * index + 1] = copyBitmap[index2];
                }
            }

            outRect.size.width  =  blendWidth;
            outRect.size.height =  blendHeight;
            outWidth  = blendWidth;
            outHeight = blendHeight;

            delete [] outlineBitmap;
            delete [] copyBitmap;
            ret = blendImage;
        }

        invalidChar = false;
    } while (0);

    if (invalidChar)
    {
        outRect.size.width  = 0;
        outRect.size.height = 0;
        xAdvance = 0;

        return nullptr;
    }
    else
    {
       return ret;
    }
}

unsigned char * FontFreeType::getGlyphBitmapWithOutline(unsigned short theChar, FT_BBox &bbox)
{   
    unsigned char* ret = nullptr;
    if (FT_Load_Char(_fontRef, theChar, FT_LOAD_NO_BITMAP) == 0)
    {
        if (_fontRef->glyph->format == FT_GLYPH_FORMAT_OUTLINE)
        {
            FT_Glyph glyph;
            if (FT_Get_Glyph(_fontRef->glyph, &glyph) == 0)
            {
                FT_Glyph_StrokeBorder(&glyph, _stroker, 0, 1);
                if (glyph->format == FT_GLYPH_FORMAT_OUTLINE)
                {
                    FT_Outline *outline = &reinterpret_cast<FT_OutlineGlyph>(glyph)->outline;
                    FT_Glyph_Get_CBox(glyph,FT_GLYPH_BBOX_GRIDFIT,&bbox);
                    long width = (bbox.xMax - bbox.xMin)>>6;
                    long rows = (bbox.yMax - bbox.yMin)>>6;

                    FT_Bitmap bmp;
                    bmp.buffer = new (std::nothrow) unsigned char[width * rows];
                    memset(bmp.buffer, 0, width * rows);
                    bmp.width = (int)width;
                    bmp.rows = (int)rows;
                    bmp.pitch = (int)width;
                    bmp.pixel_mode = FT_PIXEL_MODE_GRAY;
                    bmp.num_grays = 256;

                    FT_Raster_Params params;
                    memset(&params, 0, sizeof (params));
                    params.source = outline;
                    params.target = &bmp;
                    params.flags = FT_RASTER_FLAG_AA;
                    FT_Outline_Translate(outline,-bbox.xMin,-bbox.yMin);
                    FT_Outline_Render(_FTlibrary, outline, &params);

                    ret = bmp.buffer;
                }
                FT_Done_Glyph(glyph);
            }
        }
    }

    return ret;
}

unsigned char * makeDistanceMap( unsigned char *img, long width, long height)
{
    long pixelAmount = (width + 2 * DistanceMapSpread) * (height + 2 * DistanceMapSpread);

    short * xdist = (short *)  malloc( pixelAmount * sizeof(short) );
    short * ydist = (short *)  malloc( pixelAmount * sizeof(short) );
    double * gx   = (double *) calloc( pixelAmount, sizeof(double) );
    double * gy      = (double *) calloc( pixelAmount, sizeof(double) );
    double * data    = (double *) calloc( pixelAmount, sizeof(double) );
    double * outside = (double *) calloc( pixelAmount, sizeof(double) );
    double * inside  = (double *) calloc( pixelAmount, sizeof(double) );
    long i,j;

    // Convert img into double (data) rescale image levels between 0 and 1
    long outWidth = width + 2 * DistanceMapSpread;
    for (i = 0; i < width; ++i)
    {
        for (j = 0; j < height; ++j)
        {
            data[j * outWidth + DistanceMapSpread + i] = img[j * width + i] / 255.0;
        }
    }

    width += 2 * DistanceMapSpread;
    height += 2 * DistanceMapSpread;

    // Transform background (outside contour, in areas of 0's)   
    computegradient( data, (int)width, (int)height, gx, gy);
    edtaa3(data, gx, gy, (int)width, (int)height, xdist, ydist, outside);
    for( i=0; i< pixelAmount; i++)
        if( outside[i] < 0.0 )
            outside[i] = 0.0;

    // Transform foreground (inside contour, in areas of 1's)   
    for( i=0; i< pixelAmount; i++)
        data[i] = 1 - data[i];
    computegradient( data, (int)width, (int)height, gx, gy);
    edtaa3(data, gx, gy, (int)width, (int)height, xdist, ydist, inside);
    for( i=0; i< pixelAmount; i++)
        if( inside[i] < 0.0 )
            inside[i] = 0.0;

    // The bipolar distance field is now outside-inside
    double dist;
    /* Single channel 8-bit output (bad precision and range, but simple) */    
    unsigned char *out = (unsigned char *) malloc( pixelAmount * sizeof(unsigned char) );
    for( i=0; i < pixelAmount; i++)
    {
        dist = outside[i] - inside[i];
        dist = 128.0 - dist*16;
        if( dist < 0 ) dist = 0;
        if( dist > 255 ) dist = 255;
        out[i] = (unsigned char) dist;
    }
    /* Dual channel 16-bit output (more complicated, but good precision and range) */
    /*unsigned char *out = (unsigned char *) malloc( pixelAmount * 3 * sizeof(unsigned char) ); 
    for( i=0; i< pixelAmount; i++)
    {
        dist = outside[i] - inside[i];
        dist = 128.0 - dist*16;
        if( dist < 0.0 ) dist = 0.0;
        if( dist >= 256.0 ) dist = 255.999;
        // R channel is a copy of the original grayscale image
        out[3*i] = img[i];
        // G channel is fraction
        out[3*i + 1] = (unsigned char) ( 256 - (dist - floor(dist)* 256.0 ));
        // B channel is truncated integer part
        out[3*i + 2] = (unsigned char)dist; 
    }*/
    
    free( xdist );
    free( ydist );
    free( gx );
    free( gy );
    free( data );
    free( outside );
    free( inside );

    return out;
}

void FontFreeType::renderCharAt(unsigned char *dest,int posX, int posY, unsigned char* bitmap,long bitmapWidth,long bitmapHeight)
{
    int iX = posX;
    int iY = posY;

    if (_distanceFieldEnabled)
    {
        auto distanceMap = makeDistanceMap(bitmap,bitmapWidth,bitmapHeight);

        bitmapWidth += 2 * DistanceMapSpread;
        bitmapHeight += 2 * DistanceMapSpread;

        for (long y = 0; y < bitmapHeight; ++y)
        {
            long bitmap_y = y * bitmapWidth;

            for (long x = 0; x < bitmapWidth; ++x)
            {    
                /* Dual channel 16-bit output (more complicated, but good precision and range) */
                /*int index = (iX + ( iY * destSize )) * 3;                
                int index2 = (bitmap_y + x)*3;
                dest[index] = out[index2];
                dest[index + 1] = out[index2 + 1];
                dest[index + 2] = out[index2 + 2];*/

                //Single channel 8-bit output 
                dest[iX + ( iY * CacheTextureWidth )] = distanceMap[bitmap_y + x];

                iX += 1;
            }

            iX  = posX;
            iY += 1;
        }
        free(distanceMap);
    }
    else if(_outlineSize > 0)
    {
        unsigned char tempChar;
        for (long y = 0; y < bitmapHeight; ++y)
        {
            long bitmap_y = y * bitmapWidth;

            for (int x = 0; x < bitmapWidth; ++x)
            {
                tempChar = bitmap[(bitmap_y + x) * 2];
                dest[(iX + ( iY * CacheTextureWidth ) ) * 2] = tempChar;
                tempChar = bitmap[(bitmap_y + x) * 2 + 1];
                dest[(iX + ( iY * CacheTextureWidth ) ) * 2 + 1] = tempChar;

                iX += 1;
            }

            iX  = posX;
            iY += 1;
        }
        delete [] bitmap;
    }
    else
    {
        for (long y = 0; y < bitmapHeight; ++y)
        {
            long bitmap_y = y * bitmapWidth;

            for (int x = 0; x < bitmapWidth; ++x)
            {
                unsigned char cTemp = bitmap[bitmap_y + x];

                // the final pixel
                dest[(iX + ( iY * CacheTextureWidth ) )] = cTemp;

                iX += 1;
            }

            iX  = posX;
            iY += 1;
        }
    } 
}

void FontFreeType::setGlyphCollection(GlyphCollection glyphs, const char* customGlyphs /* = nullptr */)
{
    _usedGlyphs = glyphs;
    if (glyphs == GlyphCollection::CUSTOM)
    {
        _customGlyphs = customGlyphs;
    }
}

const char* FontFreeType::getGlyphCollection() const
{
    const char* glyphCollection = nullptr;
    switch (_usedGlyphs)
    {
    case cocos2d::GlyphCollection::DYNAMIC:
        break;
    case cocos2d::GlyphCollection::NEHE:
        glyphCollection = _glyphNEHE;
        break;
    case cocos2d::GlyphCollection::ASCII:
        glyphCollection = _glyphASCII;
        break;
    case cocos2d::GlyphCollection::CUSTOM:
        glyphCollection = _customGlyphs.c_str();
        break;
    default:
        break;
    }

    return glyphCollection;
}

void FontFreeType::releaseFont(const std::string &fontName)
{
    auto item = s_cacheFontData.begin();
    while (s_cacheFontData.end() != item)
    {
        if (item->first.find(fontName) != std::string::npos)
            item = s_cacheFontData.erase(item);
        else
            item++;
    }
}

void FontFreeType::updateFontAtlas(const std::u16string& utf16Text)
{
    std::unordered_map<unsigned short, unsigned short> codeMapOfNewChar;
    findNewCharacters(utf16Text, codeMapOfNewChar);
    if (codeMapOfNewChar.empty())
    {
        return;
    }
    
    int adjustForDistanceMap = _letterPadding / 2;
    int adjustForExtend = _letterEdgeExtend / 2;
    long bitmapWidth;
    long bitmapHeight;
    int glyphHeight;
    Rect tempRect;
    FontLetterDefinition tempDef;
    
    auto scaleFactor = CC_CONTENT_SCALE_FACTOR();
    auto  pixelFormat = getOutlineSize() > 0 ? Texture2D::PixelFormat::AI88 : Texture2D::PixelFormat::A8;
    
    float startY = _currentPageOrigY;
    
    for (auto&& it : codeMapOfNewChar)
    {
        auto bitmap = getGlyphBitmap(it.second, bitmapWidth, bitmapHeight, tempRect, tempDef.xAdvance);
        if (bitmap && bitmapWidth > 0 && bitmapHeight > 0)
        {
            tempDef.validDefinition = true;
            tempDef.width = tempRect.size.width + _letterPadding + _letterEdgeExtend;
            tempDef.height = tempRect.size.height + _letterPadding + _letterEdgeExtend;
            tempDef.offsetX = tempRect.origin.x + adjustForDistanceMap + adjustForExtend;
            tempDef.offsetY = _fontAscender + tempRect.origin.y - adjustForDistanceMap - adjustForExtend;
            
            if (_currentPageOrigX + tempDef.width > CacheTextureWidth)
            {
                _currentPageOrigY += _currLineHeight;
                _currLineHeight = 0;
                _currentPageOrigX = 0;
                if (_currentPageOrigY + _lineHeight + _letterPadding + _letterEdgeExtend >= CacheTextureHeight)
                {
                    unsigned char *data = nullptr;
                    if (pixelFormat == Texture2D::PixelFormat::AI88)
                    {
                        data = _currentPageData + CacheTextureWidth * (int)startY * 2;
                    }
                    else
                    {
                        data = _currentPageData + CacheTextureWidth * (int)startY;
                    }
                    
                    _atlasTextures[_currentPage]->updateWithData(data, 0, startY, CacheTextureWidth, CacheTextureHeight - startY);
                    
                    startY = 0.0f;
                    
                    _currentPageOrigY = 0;
                    memset(_currentPageData, 0, _currentPageDataSize);
                    _currentPage++;
                    
                    auto tex = new (std::nothrow) Texture2D;
                    
                    if (_isAntialiasEnabled)
                    {
                        tex->setAntiAliasTexParameters();
                    }
                    else
                    {
                        tex->setAliasTexParameters();
                    }
                    
                    tex->initWithData(_currentPageData, _currentPageDataSize,
                                      pixelFormat, CacheTextureWidth, CacheTextureHeight, Size(CacheTextureWidth, CacheTextureHeight));
                    
                    
                    setTexture(tex, _currentPage);
                    
                    tex->release();
                }
            }
            glyphHeight = static_cast<int>(bitmapHeight) + _letterPadding + _letterEdgeExtend;
            if (glyphHeight > _currLineHeight)
            {
                _currLineHeight = glyphHeight;
            }
            
            renderCharAt(_currentPageData, _currentPageOrigX + adjustForExtend, _currentPageOrigY + adjustForExtend, bitmap, bitmapWidth, bitmapHeight);
            
            tempDef.U = _currentPageOrigX;
            tempDef.V = _currentPageOrigY;
            tempDef.textureID = _currentPage;
            _currentPageOrigX += tempDef.width + 1;
            // take from pixels to points
            tempDef.width = tempDef.width / scaleFactor;
            tempDef.height = tempDef.height / scaleFactor;
            tempDef.U = tempDef.U / scaleFactor;
            tempDef.V = tempDef.V / scaleFactor;
        }
        else{
            if (tempDef.xAdvance)
                tempDef.validDefinition = true;
            else
                tempDef.validDefinition = false;
            
            tempDef.width = 0;
            tempDef.height = 0;
            tempDef.U = 0;
            tempDef.V = 0;
            tempDef.offsetX = 0;
            tempDef.offsetY = 0;
            tempDef.textureID = 0;
            _currentPageOrigX += 1;
        }
        
        setLetterDefinition(it.first, tempDef);
    }
    
    unsigned char *data = nullptr;
    if (pixelFormat == Texture2D::PixelFormat::AI88)
    {
        data = _currentPageData + CacheTextureWidth * (int)startY * 2;
    }
    else
    {
        data = _currentPageData + CacheTextureWidth * (int)startY;
    }
    
    _atlasTextures[_currentPage]->updateWithData(data, 0, startY, CacheTextureWidth, _currentPageOrigY - startY + _currLineHeight);
}

void FontFreeType::reset()
{
    _currLineHeight = 0;
    _currentPage = 0;
    _currentPageOrigX = 0;
    _currentPageOrigY = 0;
}

void FontFreeType::clearCache()
{
    reset();
}

void FontFreeType::conversionU16TOGB2312(const std::u16string& u16Text, std::unordered_map<unsigned short, unsigned short>& charCodeMap)
{
    size_t strLen = u16Text.length();
    auto gb2312StrSize = strLen * 2;
    auto gb2312Text = new (std::nothrow) char[gb2312StrSize];
    memset(gb2312Text, 0, gb2312StrSize);
    
    switch (_encoding)
    {
        case FT_ENCODING_GB2312:
        {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
            WideCharToMultiByte(936, NULL, (LPCWCH)u16Text.c_str(), strLen, (LPSTR)gb2312Text, gb2312StrSize, NULL, NULL);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
            conversionEncodingJNI((char*)u16Text.c_str(), gb2312StrSize, "UTF-16LE", gb2312Text, "GB2312");
#else
            if (_iconv == nullptr)
            {
                _iconv = iconv_open("gb2312", "utf-16le");
            }
            
            if (_iconv == (iconv_t)-1)
            {
                CCLOG("conversion from utf16 to gb2312 not available");
            }
            else
            {
                char* pin = (char*)u16Text.c_str();
                char* pout = gb2312Text;
                size_t inLen = strLen * 2;
                size_t outLen = gb2312StrSize;
                
                iconv(_iconv, (char**)&pin, &inLen, &pout, &outLen);
            }
#endif
        }
            break;
        default:
            CCLOG("Unsupported encoding:%d", _encoding);
            break;
    }
    
    unsigned short gb2312Code = 0;
    unsigned char* dst = (unsigned char*)&gb2312Code;
    unsigned short u16Code;
    for (size_t index = 0, gbIndex = 0; index < strLen; ++index)
    {
        u16Code = u16Text[index];
        if (u16Code < 256)
        {
            charCodeMap[u16Code] = u16Code;
            gbIndex += 1;
        }
        else
        {
            dst[0] = gb2312Text[gbIndex + 1];
            dst[1] = gb2312Text[gbIndex];
            charCodeMap[u16Code] = gb2312Code;
            
            gbIndex += 2;
        }
    }
    
    delete[] gb2312Text;
}

void FontFreeType::findNewCharacters(const std::u16string& u16Text, std::unordered_map<unsigned short, unsigned short>& charCodeMap)
{
    std::u16string newChars;
    FT_Encoding charEncoding = _encoding;
    
    //find new characters
    if (_letterDefinitions.empty())
    {
        // fixed #16169: new android project crash in android 5.0.2 device (Nexus 7) when use 3.12.
        // While using clang compiler with gnustl_static on android, the copy assignment operator of `std::u16string`
        // will affect the memory validity, it means after `newChars` is destroyed, the memory of `u16Text` holds
        // will be a dead region. `u16text` represents the variable in `Label::_utf16Text`, when somewhere
        // allocates memory by `malloc, realloc, new, new[]`, the generated memory address may be the same
        // as `Label::_utf16Text` holds. If doing a `memset` or other memory operations, the orignal `Label::_utf16Text`
        // will be in an unknown state. Meanwhile, a bunch lots of logic which depends on `Label::_utf16Text`
        // will be broken.
        
        // newChars = u16Text;
        
        // Using `append` method is a workaround for this issue. So please be carefuly while using the assignment operator
        // of `std::u16string`.
        newChars.append(u16Text);
    }
    else
    {
        auto length = u16Text.length();
        newChars.reserve(length);
        for (size_t i = 0; i < length; ++i)
        {
            if (!isLetterDefinitionExist(u16Text[i]))
            {
                newChars.push_back(u16Text[i]);
            }
        }
    }
    
    if (!newChars.empty())
    {
        switch (charEncoding)
        {
            case FT_ENCODING_UNICODE:
            {
                for (auto u16Code : newChars)
                {
                    charCodeMap[u16Code] = u16Code;
                }
                break;
            }
            case FT_ENCODING_GB2312:
            {
                conversionU16TOGB2312(newChars, charCodeMap);
                break;
            }
            default:
                CCLOG("FontAtlas::findNewCharacters: Unsupported encoding:%d", charEncoding);
                break;
        }
    }
}

NS_CC_END
