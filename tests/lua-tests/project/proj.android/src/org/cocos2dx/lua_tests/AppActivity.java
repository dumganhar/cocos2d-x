package org.cocos2dx.lua_tests;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import com.chukong.cocosplay.client.CocosPlayClient;

import android.app.Activity;
import android.os.Bundle;

public class AppActivity extends Cocos2dxActivity{

    @Override
    protected void onLoadNativeLibraries() {

    }

    @Override
    public String[] getLibraryNames() {
        return new String[] {"lua_tests"};
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (!CocosPlayClient.isEnabled())
        {
            super.onLoadNativeLibraries();
        }
        super.onCreate(savedInstanceState);
        CocosPlayClient.init(this, false);
    }

    public Cocos2dxGLSurfaceView onCreateView() {
        
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(that);
        // Tests should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
        
        return glSurfaceView;
    }
}
