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

#ifndef _CCFontFNT_h_
#define _CCFontFNT_h_

/// @cond DO_NOT_SHOW

#include "2d/CCFontAtlas.h"

NS_CC_BEGIN

class BMFontConfiguration;

class CC_DLL FontFNT : public FontAtlas
{
public:
    /** Purges the cached data.
     Removes from memory the cached configurations and the atlas name dictionary.
     */
    static void purgeCachedData();
    static void reloadBMFontResource(const std::string& fntFilePath);
    
    FontFNT();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~FontFNT();
    
    bool initWithFNTConfig(const std::string& fntFilePath, const Vec2& imageOffset = Vec2::ZERO);
    
    // Override Functions
    virtual void updateFontAtlas(const std::u16string& utf16String) override {}
    virtual int getFontMaxHeight() const override { return _lineHeight; }
    virtual float getFontSize() const override;
    virtual int* getHorizontalKerningForTextUTF16(const std::u16string& text, int &outNumLetters) const override;
    virtual void clearCache() override {}
private:
    
    int  getHorizontalKerningForChars(unsigned short firstChar, unsigned short secondChar) const;
    
    BMFontConfiguration * _configuration;
    Vec2                   _imageOffset;
    //User defined font size
//cjh    float  _fontSize;
    int _lineHeight;
};

/// @endcond

NS_CC_END

#endif /* defined(__cocos2d_libs__CCFontFNT__) */
