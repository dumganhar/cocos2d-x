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

#ifndef _FontFreetype_h_
#define _FontFreetype_h_

/// @cond DO_NOT_SHOW

#include "2d/CCFontAtlas.h"

#include <string>
#include <ft2build.h>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#define generic GenericFromFreeTypeLibrary
#define internal InternalFromFreeTypeLibrary
#endif

#include FT_FREETYPE_H
#include FT_STROKER_H

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#undef generic
#undef internal
#endif

NS_CC_BEGIN

class CC_DLL FontFreeType : public FontAtlas
{
public:
    static void shutdownFreeType();
    static void releaseFont(const std::string &fontName);
    
    FontFreeType();
    virtual ~FontFreeType();
    
    bool initWithFontFreeTypeConfig(const std::string &fontName, float fontSize, GlyphCollection glyphs,
                                    const char *customGlyphs, bool distanceFieldEnabled = false, int outline = 0);
    
    bool isDistanceFieldEnabled() const { return _distanceFieldEnabled;}

    float getOutlineSize() const { return _outlineSize; }

    void renderCharAt(unsigned char *dest,int posX, int posY, unsigned char* bitmap,long bitmapWidth,long bitmapHeight); 

    int getFontAscender() const;
    const char* getFontFamily() const;

    // Override Functions
    virtual int getFontMaxHeight() const override { return _lineHeight; }
    virtual float getFontSize() const override { return _fontSize; };
    virtual int* getHorizontalKerningForTextUTF16(const std::u16string& text, int &outNumLetters) const override;
    virtual void clearCache() override;
    virtual void updateFontAtlas(const std::u16string& utf16String) override;
    
private:

    bool createFontObject();

    bool initFreeType();
    
    int getHorizontalKerningForChars(unsigned short firstChar, unsigned short secondChar) const;
    
    unsigned char* getGlyphBitmap(unsigned short theChar, long &outWidth, long &outHeight, Rect &outRect,int &xAdvance);
    unsigned char* getGlyphBitmapWithOutline(unsigned short code, FT_BBox &bbox);

    void setGlyphCollection(GlyphCollection glyphs, const char* customGlyphs = nullptr);
    const char* getGlyphCollection() const;
    
    FT_Face _fontRef;
    FT_Stroker _stroker;
    FT_Encoding _encoding;

    std::string _fontName;
    float _fontSize;
    bool _distanceFieldEnabled;
    float _outlineSize;
    int _lineHeight;

    GlyphCollection _usedGlyphs;
    std::string _customGlyphs;
    
    // Copied from FontAtlas
    
    void reset();
    
    void findNewCharacters(const std::u16string& u16Text, std::unordered_map<unsigned short, unsigned short>& charCodeMap);
    
    void conversionU16TOGB2312(const std::u16string& u16Text, std::unordered_map<unsigned short, unsigned short>& charCodeMap);
    
    void* _iconv;
    
    // Dynamic GlyphCollection related stuff
    int _currentPage;
    unsigned char *_currentPageData;
    int _currentPageDataSize;
    float _currentPageOrigX;
    float _currentPageOrigY;
    int _letterPadding;
    int _letterEdgeExtend;
    
    int _fontAscender;
    int _currLineHeight;
};

/// @endcond

NS_CC_END

#endif
