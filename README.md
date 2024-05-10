# 矢山代码阅读器
## 目录
#### [编译运行](#编译运行)     
[1. 安装依赖](#1-安装依赖)    
[2. 下载 vcpkg](#2-下载-vcpkg如果已经下载过vcpkg可跳过这个步骤)     
[3. 下载矢山项目代码与子项目代码](#3-下载矢山项目代码与子项目代码)     
[4. 编译](#4-编译)     
[5. 指定源码位置](#5-指定源码位置)     
[6. 解析源码](#6-解析源码)     

## 编译运行
### 1. 安装依赖
`sudo apt install git cmake g++ bison flex curl libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config`

### 2. 下载 vcpkg(如果已经下载过vcpkg可跳过这个步骤)
vcpkg是一个c++包的管理与下载工具，请自行选择合适目录下载安装   
`git clone https://github.com/microsoft/vcpkg`    
`./vcpkg/bootstrap-vcpkg.sh`    

### 3. 下载矢山项目代码与子项目代码
`git clone https://github.com/doubledong94/shishandaimaViewer.git`    
`cd shishandaimaViewer/`  
`git submodule update --init --remote –recursive`    
上面这个命令（git submodule......）如果卡住或者报错，导致你想重新执行时，需要把矢山项目删除，从第三步的开头开始执行
### 4. 编译
`./configureRelease.sh  [vcpkg_path]`  
`./buildDebug.sh `    
这里的vcpkg_path是你在第二步中下载vcpkg的路径，路径要包括vcpkg文件夹本身，例：/home/ydd/github/vcpkg

### 5. 指定源码位置
`./srcPath.sh [src path]`  
第一次运行前需要告诉矢山你想读的代码存放在哪个文件夹里面。这个文件夹需要包含**java se中的类文件**（或者ee，根据个人需求），也就是java.lang/java.util/java.math等这些包里的代码。如果你的项目依赖了别的java项目，那么这个文件夹也需要包含**你所依赖的项目的源码**。     
如果你不想将**java se的代码**或者**你所依赖项目的代码**放到你的工程目录里，你可以先将[src path]指定成存放**java se代码和依赖代码**的路径，然后执行第六步，然后再将[src path]配置成你工程的路径，，然后再执行第六步。


### 6. 解析源码
这个软件没有提供install的步骤，编译后的可执行文件在：
`./build/bin/shishandaimaViewer`     
第一次运行请使用快捷键`ctrl+alt+p`，并点击yes，开始解析源码。解析完成后请关闭矢山并重新打开后才能正常使用。       
之后源码如果有改动，不需要再次指定[src path]，直接使用快捷键解析，矢山会使用你上一次制定的[src path]。


