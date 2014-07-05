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
        // TODO Auto-generated method stub
        return new String[] {"lua_tests"};
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        CocosPlayClient.init(this);
    }

    public Cocos2dxGLSurfaceView onCreateView() {
        
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(that);
        // Tests should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
        
        return glSurfaceView;
    }
}
