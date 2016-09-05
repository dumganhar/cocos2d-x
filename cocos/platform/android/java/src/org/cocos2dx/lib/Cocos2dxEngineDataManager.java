/****************************************************************************
 * Copyright (c) 2016 Chukong Technologies Inc.
 * <p/>
 * http://www.cocos2d-x.org
 * <p/>
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * <p/>
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * <p/>
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ****************************************************************************/

package org.cocos2dx.lib;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Handler;
import android.util.Log;

import org.cocos2dx.enginedata.EngineDataManager;
import org.cocos2dx.enginedata.IEngineDataManager;

public class Cocos2dxEngineDataManager {
    private static final String TAG = "CCEngineDataManager";
    private static EngineDataManager sManager = new EngineDataManager();
//    private static Context sContext;

    private Cocos2dxEngineDataManager() {

    }


    // Lifecycle functions
    public static boolean init(Context context, final GLSurfaceView glSurfaceView) {
        if (context == null) {
            Log.e(TAG, "Context is null");
            return false;
        }

        if (glSurfaceView == null) {
            Log.e(TAG, "glSurfaceView is null");
            return false;
        }

//        sContext = context;

        final IEngineDataManager.OnSystemCommandListener listener = new IEngineDataManager.OnSystemCommandListener() {

            @Override
            public void onQueryFps(final int[] expectedFps, final int[] realFps) {
//                glSurfaceView.queueEvent(new Runnable() {
//                    @Override
//                    public void run() {
                        nativeOnQueryFps(expectedFps, realFps);
//                    }
//                });
            }

            @Override
            public void onChangeContinuousFrameLostConfig(final int cycle, final int maxFrameMissed) {
                glSurfaceView.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        nativeOnChangeContinuousFrameLostConfig(cycle, maxFrameMissed);
                    }
                });
            }

            @Override
            public void onChangeLowFpsConfig(final int cycle, final float maxFrameDx) {
                glSurfaceView.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        nativeOnChangeLowFpsConfig(cycle, maxFrameDx);
                    }
                });
            }

            @Override
            public void onChangeExpectedFps(final int fps) {
                glSurfaceView.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        nativeOnChangeExpectedFps(fps);
                    }
                });
            }

            @Override
            public void onChangeSpecialEffectLevel(final int level) {
                glSurfaceView.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        nativeOnChangeSpecialEffectLevel(level);
                    }
                });
            }

            @Override
            public void onChangeMuteEnabled(final boolean enabled) {
                glSurfaceView.queueEvent(new Runnable() {
                    @Override
                    public void run() {
                        nativeOnChangeMuteEnabled(enabled);
                    }
                });
            }
        };

        return sManager.init(listener);
    }

    public static void destroy() {
//        sContext = null;
        sManager.destroy();
    }

    public static void pause() {
        sManager.pause();
    }

    public static void resume() {
        sManager.resume();
    }
    //

    public static String getVendorInfo() {
        return sManager.getVendorInfo();
    }

    private static IEngineDataManager.GameStatus convertIntegerToGameStatus(int gameStatus) {
        IEngineDataManager.GameStatus[] values = IEngineDataManager.GameStatus.values();
        for (IEngineDataManager.GameStatus status : values) {
            if (gameStatus == status.ordinal()) {
                return status;
            }
        }

        return IEngineDataManager.GameStatus.INVALID;
    }
    /*
     * @brief Notify game overhead changed
     * @param gameStatus Which situation current game is in
     * @param cpuLevel Current game wastes how much CPU resources, the range is [0,10]
     * @param gpuLevel Current game wastes how much GPU resources, the range is [0,10]
     */
    public static void notifyGameStatus(int gameStatus, int cpuLevel, int gpuLevel) {
        IEngineDataManager.GameStatus status = convertIntegerToGameStatus(gameStatus);
        if (status == IEngineDataManager.GameStatus.INVALID) {
            Log.e(TAG, "Invalid game status: " + gameStatus);
            return;
        }
        sManager.notifyGameStatus(status, cpuLevel, gpuLevel);
    }

    /*
     * @brief Notify an event that some frames are lost
     * @param cycle 统计周期，单位是毫秒，默认统计周期5000ms
     * @param maxFrameMissed 设定的连续丢帧阈值，即每100ms最大丢帧数阈值，达到或超过该阈值则判断为连续丢帧一次。默认为3。
     */
    public static void notifyContinuousFrameLost(int cycle, int maxFrameMissed, int times) {
        sManager.notifyContinuousFrameLost(cycle, maxFrameMissed, times);
    }

    /*
     * @brief Notify an event that game FPS is too low
     * @param cycle 统计周期，由手机系统设定。默认1000ms。
     * @param maxFrameDx 设定丢帧率阈值，由手机系统设定。默认值0.3。
     * @param frame 统计周期内，Cocos引擎检测到的实际丢帧数。
     */
    public static void notifyLowFps(int cycle, float maxFrameDx, int lostFrameCount) {
        sManager.notifyLowFps(cycle, maxFrameDx, lostFrameCount);
    }

    // Native methods
    private native static void nativeOnQueryFps(/*out*/ int[] expectedFps, /*out*/ int[] realFps);
    private native static void nativeOnChangeContinuousFrameLostConfig(int cycle, int maxFrameMissed);
    private native static void nativeOnChangeLowFpsConfig(int cycle, float maxFrameDx);
    private native static void nativeOnChangeExpectedFps(int fps);
    private native static void nativeOnChangeSpecialEffectLevel(int level);
    private native static void nativeOnChangeMuteEnabled(boolean enabled);
}
