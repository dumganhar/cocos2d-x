#!/bin/bash

# exit this script if any commmand fails
set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
COCOS2DX_ROOT="$DIR"/../..

mkdir -p $HOME/bin

if [ $TARGET = linux ]; then
    sh $COCOS2DX_ROOT/install-deps-linux.sh
fi

if [ $TARGET = nacl ]; then
    sudo apt-get update
    sudo apt-get install libc6:i386
    wget http://storage.googleapis.com/nativeclient-mirror/nacl/nacl_sdk/nacl_sdk.zip
    unzip nacl_sdk.zip
    nacl_sdk/naclsdk update --force pepper_canary

fi

install_android_ndk()
{
    # Download android ndk
    echo "Download android ndk ..."
    curl -O http://dl.google.com/android/ndk/android-ndk-r8e-linux-x86_64.tar.bz2
    echo "decompress android-ndk-r8e-linux-x86_64.tar.bz2 ..."
    tar xjf android-ndk-r8e-linux-x86_64.tar.bz2
    # Move ndk to home folder
    mv android-ndk-r8e $HOME/bin/android-ndk
}

if [ $TARGET = android ]; then 
    install_android_ndk
fi

if [ $TARGET = jsb ]; then 
    install_android_ndk
    # Download llvm3.1
    echo "Download llvm3.1 ..."
    curl -O http://llvm.org/releases/3.1/clang+llvm-3.1-x86_64-linux-ubuntu_12.04.tar.gz
    echo "decompress android-ndk-r8e-linux-x86_64.tar.bz2 ..."
    tar xzf clang+llvm-3.1-x86_64-linux-ubuntu_12.04.tar.gz
    # Move llvm to home folder
    mv clang+llvm-3.1-x86_64-linux-ubuntu_12.04 $HOME/bin/clang+llvm-3.1
fi

export NACL_SDK_ROOT=$DIR/nacl_sdk/pepper_canary
export PATH=$PATH:$NACL_SDK_ROOT/toolchain/linux_x86_newlib/bin
export NDK_ROOT=$HOME/bin/android-ndk

