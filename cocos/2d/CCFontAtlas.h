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

#ifndef _CCFontAtlas_h_
#define _CCFontAtlas_h_

/// @cond DO_NOT_SHOW

#include <string>
#include <unordered_map>

#include "platform/CCPlatformMacros.h"
#include "base/CCRef.h"
#include "platform/CCStdC.h" // ssize_t on windows
#include "renderer/CCTexture2D.h"

NS_CC_BEGIN

class Font;
class Texture2D;
class EventCustom;
class EventListenerCustom;

struct FontLetterDefinition
{
    float U;
    float V;
    float width;
    float height;
    float offsetX;
    float offsetY;
    int textureID;
    bool validDefinition;
    int xAdvance;
};

class CC_DLL FontAtlas : public Ref
{
public:
    static const char* CMD_PURGE_FONTATLAS;
    static const char* CMD_RESET_FONTATLAS;
    
    /**
     * @js NA
     * @lua NA
     */
    virtual ~FontAtlas();
    
    // Abstract methods
    virtual void updateFontAtlas(const std::u16string& utf16String) = 0;
    virtual int* getHorizontalKerningForTextUTF16(const std::u16string& text, int &outNumLetters) const = 0;
    virtual int getFontMaxHeight() const = 0;
    virtual float getFontSize() const = 0;
    virtual void clearCache() = 0;
    //
    
    inline bool isLetterDefinitionExist(char16_t utf16Char) { return _letterDefinitions.find(utf16Char) != _letterDefinitions.end(); }
    
    FontLetterDefinition getLetterDefinition(char16_t utf16Char);
    
    inline void clearLetterDefinitionMap() { _letterDefinitions.clear(); }
    inline bool isEmptyOfLetterDefinitionMap() { return _letterDefinitions.empty(); }
    
    const std::unordered_map<ssize_t, Texture2D*>& getTextures() const { return _atlasTextures; }
    Texture2D* getTexture(int slot);
    
    void releaseTextures();
    
    /** Removes textures atlas.
     It will purge the textures atlas and if multiple texture exist in the FontAtlas.
     */
    void purgeTexturesAtlas();
    
    /** sets font texture parameters:
    - GL_TEXTURE_MIN_FILTER = GL_LINEAR
    - GL_TEXTURE_MAG_FILTER = GL_LINEAR
    */
    void setAntiAliasTexParameters();

    /** sets font texture parameters:
    - GL_TEXTURE_MIN_FILTER = GL_NEAREST
    - GL_TEXTURE_MAG_FILTER = GL_NEAREST
    */
    void setAliasTexParameters();
    
    inline bool isAntiAliasingEnabled() { return _antialiasEnabled; }

protected:
    
    /**
     * @js ctor
     */
    FontAtlas();
    
    void setLetterDefinition(char16_t utf16Char, const FontLetterDefinition &letterDefinition) { _letterDefinitions[utf16Char] = letterDefinition; }
    void setTexture(Texture2D *texture, int pageIndex);
    
    /** listen the event that renderer was recreated on Android/WP8
     It only has effect on Android and WP8.
     */
    void listenRendererRecreated(EventCustom *event);
    
    /**
     * Scale each font letter by scaleFactor.
     *
     * @param scaleFactor A float scale factor for scaling font letter info.
     */
    void scaleFontLetterDefinition(float scaleFactor);

    std::unordered_map<ssize_t, Texture2D*> _atlasTextures;
    std::unordered_map<char16_t, FontLetterDefinition> _letterDefinitions;

    bool _antialiasEnabled;
    
    EventListenerCustom* _rendererRecreatedListener;
    
    friend class Label;
};

NS_CC_END

/// @endcond
#endif /* defined(__cocos2d_libs__CCFontAtlas__) */
