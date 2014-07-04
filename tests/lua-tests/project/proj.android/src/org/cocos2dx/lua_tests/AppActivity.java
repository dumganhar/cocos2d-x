package org.cocos2dx.lua_tests;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import com.chukong.cocosplay.client.CocosPlayClient;

import android.app.Activity;
import android.os.Bundle;

public class AppActivity extends Cocos2dxActivity{

    private static String sPackageName = null;
    private static Activity sProxyActivity = null;
    
    
    
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
        sProxyActivity = that;
    }

    public Cocos2dxGLSurfaceView onCreateView() {
        
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(that);
        // Tests should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
        
        return glSurfaceView;
    }
    
    public static void cocosplay_setPackageName(String packageName) {
        sPackageName = packageName.replace("/", ".");
    }
    
    public static void cocosplay_updateAssets(String filePath) {
            CocosPlayClient.updateAssetsAndReturnFullPath(sProxyActivity, sPackageName, filePath);
    }
    
    public static boolean cocosplay_fileExists(String filePath) {
            return CocosPlayClient.fileExists(sProxyActivity, sPackageName, filePath);
    }
    
    public static String cocosplay_getGameRoot() {
            return CocosPlayClient.getGameRoot(sProxyActivity, sPackageName);
    }
}
