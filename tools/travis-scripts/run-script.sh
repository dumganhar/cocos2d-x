#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
COCOS2DX_ROOT="$DIR"/../..

if [ $TARGET = android ]; then 
    cd $COCOS2DX_ROOT/samples/$SAMPLE_LANG/$APPNAME/proj.android
    ./build_native.sh
fi

if [ $TARGET = nacl ]; then
    cd $COCOS2DX_ROOT
    make -j4
fi

if [ $TARGET = linux ]; then
    cd $COCOS2DX_ROOT
    make -j4
fi

if [ $TARGET = jsb ]; then
    cd $COCOS2DX_ROOT/tools/travis-scripts
    ./generate-jsbindings.sh
fi