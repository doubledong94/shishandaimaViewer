# 矢山代码阅读器
## 目录
#### [编译运行](#编译运行-1)     
[1. 安装依赖](#1-安装依赖)    
[2. 下载 vcpkg](#2-下载-vcpkg如果已经下载过vcpkg可跳过这个步骤)     
[3. 下载矢山项目代码与子项目代码](#3-下载矢山项目代码与子项目代码)     
[4. 编译](#4-编译)     
[5. 指定源码位置](#5-指定源码位置)     
[6. 解析源码](#6-解析源码)     
#### [搜索源码](#搜索源码-1)     
[基本思路(必看)](#基本思路必看)  
[正则的字符](#正则的字符)  
[类范围](#类范围)  
[使用正则搜索](#使用正则搜索)  
[相交搜索](#相交搜索)  
#### [阅读源码](#阅读源码-1)     
#### [项目方案](#项目方案-1)     

## 编译运行
矢山目前只能在linux上编译运行
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
之后你的源码如果有改动，不需要再次指定[src path]，直接使用快捷键解析，矢山会使用你上一次指定的[src path]。

## 搜索源码
### 基本思路(必看)      
矢山的基本思路是将搜索代码分为五个方向:    
1. 时机传递方向
2. 逻辑控制方向
3. 数据流动方向
4. 类嵌套方向（对象引用）
5. 执行顺序方向（目前没有实现）

通过对这个五个方向的搜索，可以对所有java代码进行非常精确的搜索。所谓“精确”的意思是：对于任意一段代码，都可以通过这五个方向的组合，唯一的定位到它。(执行顺序方向 的搜索与展示目前没有实现)       
**矢山使用了正则搜索的方式搜索上面提到的五个方向。**    
### 正则的字符
用户可以通过下面的规则自定义正则搜索中使用的**普通字符**：   
1. 属性/函数的全名，代码这个一个属性/函数（全名不需要用户打字输入，用户此时不必在意全名是如何定义的）
2. 属性/函数全名的数组，代表一组属性/函数
3. fieldOf(C)，代表C类中的所有属性
4. methodOf(C)，代表C类中的所有函数
5. parameterOf(M)，代表M函数中的所有形参
6. returnOf(M)，代表M函数的返回
7. instanceOf(C1,C2)，代表声明在C1类中，类型为C2的属性
8. creatorOf(C)，代表C类的构造函数
9. calledMethod(M)，请看[时机传递方向](#时机传递方向)
10. calledParam(P)，请看[时机传递方向](#时机传递方向)
11. calledReturn(R)，请看[时机传递方向](#时机传递方向)
12. intersection(A1,A2)，代表A1和A2的交集
13. union(A1,A2)，代表A1和A2的并集
14. difference(A1,A2)，代表A1和A2的差集，A1-A2

正则搜索使用的**特殊字符**有：
1. Any，代表任一个**普通字符**以及没有被**普通字符**表示的局部变量和操作符（+-*/等）       
2. Reference，可搜索类嵌套方向
3. Condition，可搜索时机传递与逻辑控制方向
4. Else，可搜索逻辑控制方向
5. Step，可搜索时机传递方向

### 类范围
一个项目会有成千上万个类，而矢山在搜索时，需要把所搜索的类加载到内存中。如果为了搜一个类要把上万个类都加载到内存中，是非常不划算的。因此用户需要指定搜索范围，也就是要指定：你搜索的时机传递/数据流动等，发生在哪些类的函数中。
指定类范围的方式有：
1. 类的全名，代表这个类
2. 类全名的数组，代表一组类
3. inPackage(P)，代表包P中的所有类
4. usedBy(C)，代表被C类使用的所有类
5. use(C)，代表使用了C类的所有类
6. super(C)，代表C的父类，不包括父类的父类
7. sub(C)，代表C的子类，不包括子类的子类
8. intersection(A1,A2)，代表A1和A2的交集
9. union(A1,A2)，代表A1和A2的并集
10. difference(A1,A2)，代表A1和A2的差集，A1-A2

被定义好的**类范围**，可以用来定义**普通字符**

### 使用正则搜索
有了上面定义好的**正则字符**和**类范围**，就可以开始定义搜索了，下面会用例子的方式介绍如何定义搜索
#### 时机传递方向

#### 逻辑控制方向

#### 数据流动方向

#### 类嵌套方向

#### 执行顺序方向(目前没有实现)

### 相交搜索

## 阅读源码

## 项目方案
|功能|三方工具|
|---|---|
|源码解析|[antlr4](https://github.com/antlr/antlr4)|
|GUI|[imgui](https://github.com/ocornut/imgui)|
|正则搜索|[re2](https://github.com/google/re2)+[swipl](https://github.com/SWI-Prolog/swipl-devel)|
|绘制搜索结果|[threepp](https://github.com/markaren/threepp)|
|力导布局与其他图算法|[igraph](https://github.com/igraph/igraph)|

