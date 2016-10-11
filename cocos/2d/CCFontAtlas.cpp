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

#include "2d/CCFontAtlas.h"

#include "renderer/CCTexture2D.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventType.h"

NS_CC_BEGIN

const char* FontAtlas::CMD_PURGE_FONTATLAS = "__cc_PURGE_FONTATLAS";
const char* FontAtlas::CMD_RESET_FONTATLAS = "__cc_RESET_FONTATLAS";

FontAtlas::FontAtlas()
: _isAntialiasEnabled(true)
, _rendererRecreatedListener(nullptr)
{
#if CC_ENABLE_CACHE_TEXTURE_DATA
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    
    _rendererRecreatedListener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, CC_CALLBACK_1(FontAtlas::listenRendererRecreated, this));
    eventDispatcher->addEventListenerWithFixedPriority(_rendererRecreatedListener, 1);
#endif
}

FontAtlas::~FontAtlas()
{
#if CC_ENABLE_CACHE_TEXTURE_DATA
    if (_fontFreeType && _rendererRecreatedListener)
    {
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();
        eventDispatcher->removeEventListener(_rendererRecreatedListener);
        _rendererRecreatedListener = nullptr;
    }
#endif
    
    releaseTextures();
}

void FontAtlas::releaseTextures()
{
    for( auto &item: _atlasTextures)
    {
        item.second->release();
    }
    _atlasTextures.clear();
}


void FontAtlas::scaleFontLetterDefinition(float scaleFactor)
{
    for (auto&& fontDefinition : _letterDefinitions) {
        auto& letterDefinition = fontDefinition.second;
        letterDefinition.width *= scaleFactor;
        letterDefinition.height *= scaleFactor;
        letterDefinition.offsetX *= scaleFactor;
        letterDefinition.offsetY *= scaleFactor;
        letterDefinition.xAdvance *= scaleFactor;
    }
}

FontLetterDefinition FontAtlas::getLetterDefinition(char16_t utf16Char)
{
    FontLetterDefinition ret;
    
    auto outIterator = _letterDefinitions.find(utf16Char);

    if (outIterator != _letterDefinitions.end())
    {
        ret = (*outIterator).second;
    }
    else
    {
        ret.validDefinition = false;
    }
    
    return ret;
}

void FontAtlas::setTexture(Texture2D *texture, int pageIndex)
{
    texture->retain();
    _atlasTextures[pageIndex] = texture;
}

Texture2D* FontAtlas::getTexture(int slot)
{
    return _atlasTextures[slot];
}

void FontAtlas::setAliasTexParameters()
{
    if (_isAntialiasEnabled)
    {
        _isAntialiasEnabled = false;
        for (const auto & tex : _atlasTextures)
        {
            tex.second->setAliasTexParameters();
        }
    }
}

void FontAtlas::setAntiAliasTexParameters()
{
    if (!_isAntialiasEnabled)
    {
        _isAntialiasEnabled = true;
        for (const auto & tex : _atlasTextures)
        {
            tex.second->setAntiAliasTexParameters();
        }
    }
}

void FontAtlas::purgeTexturesAtlas()
{
    releaseTextures();
    _letterDefinitions.clear();
    
    clearCache();
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->dispatchCustomEvent(CMD_PURGE_FONTATLAS,this);
    eventDispatcher->dispatchCustomEvent(CMD_RESET_FONTATLAS,this);
}

void FontAtlas::listenRendererRecreated(EventCustom *event)
{
    purgeTexturesAtlas();
}

NS_CC_END
