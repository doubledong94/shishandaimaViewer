# 矢山代码阅读器
矢山代码阅读器是一个图形化的代码阅读器。目前的目标是：将程序员阅读代码的方式从一维的文字结构中解放出来。

视频介绍：https://www.bilibili.com/video/BV1nWeZeVEzg
## 目录
#### [编译运行](#编译运行-1)     
[1. 安装依赖](#1-安装依赖)    
[2. 下载 vcpkg](#2-下载-vcpkg如果已经下载过vcpkg可跳过这个步骤)     
[3. 下载矢山项目代码与子项目代码](#3-下载矢山项目代码与子项目代码)     
[4. 编译](#4-编译)     
[5. 指定源码位置](#5-指定源码位置)     
[6. 解析源码](#6-解析源码)     
#### [源码搜索的思路](#源码搜索的思路-1)     
[基本思路](#基本思路)  
[正则的字符](#正则的字符)  
[类范围](#类范围)  
[使用正则搜索](#使用正则搜索)  
[相交搜索](#相交搜索)  
[如何将你定义好的正则分享给其他人](#如何将你定义好的正则分享给其他人)   
#### [源码搜索的操作](#源码搜索的操作-1)     
#### [阅读源码](#阅读源码-1)     
[选择节点](#选择节点)   
[图布局](#图布局)   
[图样式(大小与颜色)](#图样式大小与颜色)   
[删除节点](#删除节点)   
[探索模式](#探索模式)   
[保存到下一轮](#保存到下一轮)   
[保存恢复图](#保存恢复图)       
#### [项目方案](#项目方案-1)     

## 编译运行
矢山目前只能在linux上编译运行
### 1. 安装依赖
```
sudo apt install git cmake g++ bison flex curl libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config libpcl-dev
```

### 2. 下载 vcpkg(如果已经下载过vcpkg可跳过这个步骤)
vcpkg是一个c++包的管理与下载工具，请自行选择合适目录下载安装   
```
git clone https://github.com/microsoft/vcpkg
```    
```
./vcpkg/bootstrap-vcpkg.sh
```    

### 3. 下载矢山项目代码与子项目代码
```
git clone https://github.com/doubledong94/shishandaimaViewer.git
```    
```
cd shishandaimaViewer/
```  
```
git submodule update --init --remote --recursive
```    
上面这个命令（git submodule......）如果卡住或者报错，导致你想重新执行时，需要把矢山项目删除，从[第三步](#3-下载矢山项目代码与子项目代码)的开头开始执行
### 4. 编译
```
./configureRelease.sh [vcpkg_path]
```  
```
./buildRelease.sh
```    
这里的 [vcpkg_path] 是你在第二步中下载vcpkg的路径，路径要包括vcpkg文件夹本身，例：/home/ydd/github/vcpkg

### 5. 指定源码位置
```
./srcPath.sh [src_path]
```  
第一次运行前需要告诉矢山你想读的代码存放在哪个文件夹里面。这个文件夹需要包含**java se中的类文件**（或者ee，根据个人需求），也就是java.lang/java.util/java.math等这些包里的代码。如果你的项目依赖了别的java项目，那么这个文件夹也需要包含**你所依赖的项目的源码**。     
如果你不想将**java se的代码**或者**你所依赖项目的代码**放到你的工程目录里，你可以先将[src path]指定成存放**java se代码和依赖代码**的路径，然后执行第六步，然后再将[src path]配置成你工程的路径，，然后再执行第六步。


### 6. 解析源码
这个软件没有提供install的步骤，编译后的可执行文件在：     
```
./build/bin/shishandaimaViewer
```     
第一次打开矢山界面后，请使用快捷键`ctrl+alt+p`，并点击yes，开始解析源码。解析完成后请关闭矢山并重新打开后才能正常使用。       
之后你的源码如果有改动，不需要再次指定[src_path]，直接使用快捷键解析，矢山会使用你上一次指定的[src_path]。

## 源码搜索的思路
### 基本思路
矢山是个图形化的代码阅读器，那么它和搜索有什么关系呢？   
试想如果一次性将所有代码都用图表示出来并绘制到屏幕上，那么不仅会冲击电脑性能的极限，也会冲击人脑分辨画面的极限。因此矢山只绘制用户搜索（感兴趣）的部分代码。   
矢山的基本思路是将搜索代码分为**5个方向**:    
1. 时机传递方向（函数调用）
2. 逻辑控制方向（条件语句）
3. 数据流动方向（赋值，传参，返回值）
4. 类嵌套方向（或者叫做域嵌套方向）（对象引用，数组访问）
5. 执行顺序方向（目前没有实现）

通过对这个**5个方向**的搜索，可以对所有java代码进行非常精确的搜索。所谓“精确”的意思是：对于任意一段代码，都可以通过这**5个方向**的组合，唯一的定位到它。(执行顺序方向 的搜索与展示目前没有实现)       
**矢山使用了正则搜索的方式搜索上面提到的5个方向。**    
### 正则的字符
用户可以通过下面的规则自定义正则搜索中使用的**普通字符**：   
1. 属性/函数的全名，代码这个一个属性/函数（全名不需要用户打字输入，用户此时不必在意全名是如何定义的）
2. 属性/函数全名的数组，匹配一组属性/函数
3. fieldOf(C)，匹配C类中的所有属性
4. instanceOf(C1,C2)，匹配声明在C1类中，类型为C2的属性
5. methodOf(C)，匹配C类中的所有函数
6. constructorOf(C)，匹配C类的构造函数
7. parameterOf(M)，匹配M函数中的所有形参
8. returnOf(M)，匹配M函数的返回
9. calledMethod(M)，具体请看[时机传递方向](#时机传递方向)
10. calledParam(P)，具体请看[数据流动方向](#数据流动方向)
11. calledReturn(R)，具体请看[数据流动方向](#数据流动方向)
12. methodUsedBy(M)，匹配被M使用的函数
13. fieldUsedBy(M)，匹配被M使用的属性
14. methodUse(A)，匹配使用A的函数，A可以是属性或者函数
12. intersection(A1,A2)，匹配A1和A2的交集
13. union(A1,A2)，匹配A1和A2的并集
14. difference(A1,A2)，匹配A1和A2的差集，A1-A2
15. var(A)，匹配一个变量，值为A，A是一个定义好的字符

正则搜索使用的**特殊字符**有：
1. Any，匹配除 “**普通字符**和其他**特殊字符**“ 外的所有字符，即操作符（+-*/等）（操作符只能用Any表示）       
1. Literal，匹配一个literal值（如：1,1.5这样的数值，"hello"这样的字符串，true，false等）
9. LV，匹配任意局部变量      
9. Field，匹配任意属性      
1. Parameter，匹配任意函数的参数      
1. Return，匹配任意函数的返回      
1. Method，匹配任意函数（包括构造函数）      
1. Constructor，匹配任意构造函数      
1. Class 匹配一个类      
1. CalledParameter，匹配任意CalledParameter      
1. CalledReturn，匹配任意CalledReturn      
1. CalledMethod，匹配任意函数对应的CalledMethod      
3. Condition，可搜索时机传递与逻辑控制方向，具体请看[时机传递方向](#时机传递方向) [逻辑控制方向](#逻辑控制4. Else，可搜索时机传递与逻辑控制方向，具体请看[时机传递方向](#时机传递方向) [逻辑控制方向](#逻辑控制方向)
方向)
2. Reference，可搜索类嵌套方向，具体请看[类嵌套方向](#类嵌套方向)
1. Index，匹配数组访问
5. DataStep，可搜索跨函数的数据流动方向，具体请看[数据流动方向](#数据流动方向)
7. DataOverride，可搜索跨函数的数据流动方向（多态）
6. TimingStep，可搜索时机传递方向，具体请看[时机传递方向](#时机传递方向)
8. TimingOverride，可搜索时机传递方向（多态）

### 类范围
一个项目会有成千上万个类，而矢山在搜索时，需要把所搜索的类加载到内存中。如果为了搜一个类要把上万个类都加载到内存中，是非常不划算的。因此用户需要指定搜索范围，也就是要指定：你搜索的时机传递/数据流动等，发生在哪些类的函数中。
指定类范围的方式有：
1. 类的全名，匹配这个类
2. 类全名的数组，匹配一组类
3. inPackage(P)，匹配包P中的所有类
6. super(C)，匹配C的父类，包括父类的父类，以及父类的父类的父类...
7. sub(C)，匹配C的子类，包括子类的子类，以及子类的子类的子类...
8. intersection(A1,A2)，匹配A1和A2的交集
9. union(A1,A2)，匹配A1和A2的并集
10. difference(A1,A2)，匹配A1和A2的差集，A1-A2
11. var(A)，匹配一个变量，值为A，A是一个定义好的类范围

被定义好的**类范围**，可以用来定义**普通字符**。比如在使用规则fieldOf(C)定义**普通字符**时，定义好的**类范围**可以替换C。

### 使用正则搜索
有了定义好的**正则字符**和**类范围**，就可以开始定义搜索了，下面会用例子的方式介绍如何定义搜索。
#### 时机传递方向
时机传递对应的是函数调用。为了让代码能被正则搜索，矢山给函数调用场景添加了一些特殊节点类型。由于这些节点类型不像fieldOf那样直观，需要进行说明。        

**举例**说明**普通字符**规则calledMethod 和 **特殊字符**TimingStep    
```java
class A {
    void a() {

    }
    void b() {
        a();
    }
    void c() {
        b();
    }
}
```
对于上面的函数调用，在矢山中的时机传递表示为：    
发生在A.c中：  A.c::: -> A.b:::# -> TimingStep -> A.b:::     
发生在A.b中：  A.b::: -> A.a:::# -> TimingStep -> A.a:::     
其中这些冒号是矢山表示函数的方式，->表示传递方向。有#号后缀的就是函数的calledMethod节点，此类节点区别于函数本身。例如当b中调用了5次a时，就会有5个a的calledMethod节点，这些节点都指向TimingStep，然后TimingStep指向唯一的a节点。    

**举例**说明**特殊字符**Condition 和 Else   
```java
class A {
    bool c1;
    bool c2;
    void a1() {

    }
    void a2() {

    }
    void a3() {

    }
    void b() {
        if (c1) {
            a1();
        } else if(c2) {
            a2();
        } else {
            a3();
        }
    }
}
``` 
对于上面的函数调用，在矢山中的时机传递表示为：    
A.b::: -> Condition1 -> A.a1:::# -> TimingStep -> A.a1:::     
A.b::: -> Condition2 -> A.a2:::# -> TimingStep -> A.a2:::     
A.b::: -> Condition3 -> A.a3:::# -> TimingStep -> A.a3:::     
这里的Condition对应于代码中的条件分支，函数b中有三个条件分支，因此有三个Condition节点。这三个Condition节点之间有Else节点连接：     
Condition1->Else->Condition2->Else->Condition3    

**举例**说明时机传递方向的搜索      
搜索在类android.view.View中调用的所有构造函数  
```
// 定义类范围
ClassScope class_view = "android.view.View";
ClassScope class_usedBy_view = usedBy ( class_view );

// 定义正则普通字符
Node method_view = MethodOf ( class_view );
Node creator_usedBy_view = CreatorOf ( class_usedBy_view );
Node called_creator_usdedBy_view = CalledMethodOf ( creator_usedBy_view );

// 定义正则搜索
Line timing_created_by_view = method_view->Condition*->called_creator_usdedBy_view;

```
搜索结果:  
![timing_created_by_view](/imgForReadMe/timing_created_by_view.png "timing_created_by_view")

搜索android.view.View类内部的函数调用栈    
```
// 定义类范围
ClassScope class_view = "android.view.View";

// 定义正则普通字符
Node method_view = MethodOf ( class_view );
Node called_method_view = CalledMethodOf ( method_view );

// 定义正则搜索
Line timing_call_stack_of_view = method_view->Condition*->called_method_view->TimingStep->method_view;

```
搜索结果：
![timing_call_stack_of_view](/imgForReadMe/timing_call_stack_of_view.png "timing_call_stack_of_view")

#### 逻辑控制方向
逻辑控制对应的是if/for/while语句中的条件表达式。    

**举例**说明**特殊字符**Condition 和 Else   
```java
class A {
    bool c1;
    bool c2;
    void a1() {

    }
    void a2() {

    }
    void a3() {

    }
    void b() {
        if (c1) {
            a1();
        } else if(c2) {
            a2();
        } else {
            a3();
        }
    }
}
``` 
对于上面的条件语句，在矢山中的逻辑控制表示为：    
c1 -> Condition1    
c2 -> Condition2    
这里的Condition对应于代码中的条件分支，由于第三个分支没有条件语句，因此只有两个Condition。但第三个Condition节点还是存在的，且这三个Condition节点之间有Else节点连接：     
Condition1->Else->Condition2->Else->Condition3   

**举例**说明逻辑控制方向的搜索      
搜索"android.view.View.mViewFlags"控制了哪些函数的调用    
(为了让例子看起来简单点，例子中的Any匹配了**普通字符**，实际使用中则不会)
```
// 定义类范围
ClassScope class_view = "android.view.View";
ClassScope class_usedBy_view = usedBy ( class_view );

// 定义正则普通字符
Node field_view_flag = "android.view.View.mViewFlags" ("android.view.View");
Node method_usedBy_view = MethodOf ( class_usedBy_view );
Node called_method_usedBy_view = CalledMethodOf ( method_usedBy_view );

// 定义正则搜索
Line logic_controledBy_flag_view = field_view_flag->Any*->Condition*->called_method_usedBy_view;

```
搜索结果:  
![logic_controledBy_flag_view](/imgForReadMe/logic_controledBy_flag_view.png "logic_controledBy_flag_view")
#### 数据流动方向
数据流动对应的是赋值，传参和函数返回。     

**举例**说明**普通字符**规则calledParam calledReturn 和 **特殊字符**DataStep          
```
class A {
    int mI;
    void a(int i) {
        return i+1;
    }
    void b(int i) {
        return a(i);
    }
    void c() {
        mI = b(mI);
    }
}
```
对于上面的传参与返回值，在矢山中的数据流动表示为：     
发生在A.c中：  A.mI -> A.b::int:i# -> DataStep -> A.b::int:i       
发生在A.b中：  A.b::int:i -> A.a::int:i# -> DataStep -> A.a::int:i      
发生在A.a中：  A.a::int:i -> + -> A.a::int:return -> DataStep -> A.a::int:return#     
发生在A.b中：  A.a::int:return# -> A.b::int:return -> DataStep -> A.b::int:return#     
发生在A.c中：  A.b::int:return# -> A.mI     
从上面可以看出，对于正向的数据流动，calledParam指向DataStep指向param，而return指向DataStep指向calledReturn，与param正好相反。    
为了表达calledParam，calledReturn，calledMethod的关系，数据流动的表示需要增加：   
发生在A.c中：  A.b::int:i# -> A.b::int:# -> A.b::int:return#        
发生在A.b中：  A.a::int:i# -> A.a::int:# -> A.a::int:return#        

**举例**说明数据流动方向的搜索      
搜索：构造android.view.View对象时，给它的参数context是如何被使用的    
(为了让例子看起来简单点，例子中的Any匹配了**普通字符**，实际使用中则不会)
```
// 定义类范围
ClassScope class_view = "android.view.View";

// 定义正则普通字符
Node param_of_constructor_view = "android.view.View.View::Context,AttributeSet,Integer,Integer:context" ("android.view.View");

// 定义正则搜索
Line dataFlow_from_paramOf_constructor_view = param_of_constructor_view->Any+;

```
搜索结果：
![dataFlow_from_param_of_constructor_view](/imgForReadMe/dataFlow_from_param_of_constructor_view.png "dataFlow_from_param_of_constructor_view")
#### 类嵌套方向
类嵌套对应的是引用对象属性和函数这个动作。  

**举例**说明**特殊字符**Reference   
```java
class A {
    int i;
    void a(int i) {
        this.i = i;
    };
}

class B {
    A a;
    void b() {
        a.a(1);
    }
}
```
对于上面的引用对象函数，在矢山中的类嵌套表示为：      
B.a -> Reference -> A.a::int:#     
注意这里使用的是calledMethod节点。       

**举例**说明类嵌套方向的搜索      
上面搜索到的结果非常少，大概是因为没有搜索类嵌套方向，下面我们加入类嵌套方向的搜索   
(为了让例子看起来简单点，例子中的Any匹配了**普通字符**，实际使用中则不会)
```
// 定义类范围
ClassScope class_view = "android.view.View";

// 定义正则普通字符
Node param_of_constructor_view = "android.view.View.View::Context,AttributeSet,Integer,Integer:context" ("android.view.View");

// 定义正则搜索
Line dataFlow_with_ref_from_paramOf_constructor_view = param_of_constructor_view->Any*->Reference*->Any+;

```
搜索结果：
![dataFlow_with_ref_from_param_of_constructor_view](/imgForReadMe/dataFlow_with_ref_from_param_of_constructor_view.png "dataFlow_with_ref_from_param_of_constructor_view")

#### 执行顺序方向(目前没有实现)

### 相交搜索
到此我们已经介绍了所谓的**5个方向**的搜索。但有些情况，单一的搜索方向不能满足需求，需要我们同时从不同方向进行搜索。上面[类嵌套方向](#类嵌套方向)的例子中，我们已经看到了数据流动和类嵌套这两个方向上同时搜索的一个例子（虽然这个例子没有用到相交的方式搜索）。下面举个例子进一步说明如何使用相交搜索的方式同时搜索两个方向。   
```java
class A {
    int i;
    void a(int i) {
        this.i = i;
    };
}

class B {
    A a1;
    int i1;
    A a2;
    int i2;
    A a3;
    int i3;
    void b1() {
        a1.a(i1);
    }
    void b2() {
        a2.a(i2);
    }
    void b3() {
        a3.a(i3);
    }
}
```
目标是找到B的哪个函数将i1传入到a1中。此时我们一眼就能看出答案是函数b1。但如果代码十分复杂：B中有100个类型为A的属性，并在1000个地方调用了A.a，我们不愿一个一个去查找时，该如何使用矢山帮助我们找到函数b1？   
答案：分别定义两个方向的搜索，并指定两个搜索相交的位置。   
方向1：数据流动：B.i1->A.a::int:i#->A.a::int:#     
方向2：类嵌套：B.a1->Reference->A.a::int:#   
指定交点：A.a::int:#

### 如何将你定义好的正则分享给其他人
你定义的正则以文字的形式保存在硬盘中，路径是：     
```
./build/config/simpleView.config
```
复制这个文件中的内容发给其他人，让他粘贴到自己本地的对应文件末尾就行。注意不要覆盖他自己的文件。

## 源码搜索的操作
快捷键 `e` 打开正则编辑面板
![regex_editing_panel](/imgForReadMe/regex_editing_panel.png "regex_editing_panel")

正则编辑面板的左侧三个面板分别用于编辑**类范围**，**正则普通字符**和**正则搜索**，点击第三个面板右下角的按钮，可以显示用于编辑**相交搜索**的第四个面板

正则编辑面板的右侧是搜索框，可以使用正则搜索类全名。搜索结果列表显示在搜索框下。当搜索结果列表不为空时，再次使用正则搜索，会将搜索范围限制在上一次的搜索结果中。清空搜索框并回车，可以清空搜索结果列表。       
双击搜索列表中的类全名，可以显示这个类的所有属性和函数。

拖拽搜索框左侧蓝色竖长条可以调整搜索框的宽度，拖拽其他两个横长条可以调整对应面板的高度。      

编辑好正则搜索后，快捷键 `esc` 退出编辑面板，然后：     
快捷键 `g` 切换搜索深度      
快捷键 `a` 选择类范围作为搜索范围    
快捷键 `s` 选择正则搜索    
快捷键 `d` 选择相交搜索     
快捷键 `shift + a` 或 `shift + s` 或 `shift + d` 取消对应的选择    
快捷键 `ctrl + f` 开始搜索    

## 阅读源码
快捷键 `1` 打开快捷键查看/编辑面板，快捷键 `esc` 退出面板

### 缩放平移
空格 + +/- 进行缩放    
空格 + 方向键进行平移

### 选择节点
1. 鼠标点击节点进行选择
    1. 单击节点可以选择和取消选择节点    
    2. ctrl + 单击节点，选择节点所在组中的所有节点
    3. [4][5-9] + 单击节点，在所选维度上，选择与被点击节点联通的所有节点
2. 键盘作用于节点进行选择    
    1. 快捷键 `ctrl + a` 选择所有节点      
    2. 快捷键 `c` 取消选择所有节点      
    3. 快捷键 `shift + /` 反向选择
    4. 快捷键 `,` 沿着已经选中的节点向上选择节点
    5. 快捷键 `.` 沿着已经选中的节点向下选择节点
    6. 快捷键 `l + b` 查找连线并选择连线，如果不存在连线，则不新增选中的节点
    7. 快捷键 `l + u` 向上查找共同父节点，并选择连线，如果不存在共同父节点，则不新增选中的节点
    8. 快捷键 `l + d` 向下查找共同子节点，并选择连线，如果不存在共同子节点，则不新增选中的节点
3. 选择列表选项进行选择
    1. 快捷键 `r` 打开节点选择面板
![selection_panel](/imgForReadMe/selection_panel.png "selection_panel")
面板左侧有三种选择节点的方式，      
（1）按照节点在正则表达式中的位置选择节点，      
（2）按照节点所属的**字符**选择节点，      
（3）按照节点发生在哪个函数来选择节点     
选择左侧的筛选规则后，右侧会出现对应的节点列表，选择右侧的节点后，使用快捷键 `esc` 退出面板，就可以选中节点了。   
    2. 快捷键 `ctrl + k` 按照节点类型选择，比如选择所有类型为 Field 的节点
    3. 快捷键 `ctrl + ;` 按照度选择节点
    4. 快捷键 `ctrl + ,` 按照入度选择节点
    5. 快捷键 `ctrl + .` 按照出度选择节点
    6. 快捷键 `ctrl + m` 按照函数深度选择节点
    7. 快捷键 `p` 按照联通子图选择节点
    8. 快捷键 `ctrl + p` 按照组选择节点
4. 快捷键 `f` 切换多次选择的累积效果
    1. select from all 表示下一次选择的节点和当前选中的节点的并集会成为下一次选中的节点（越选越多）
    2. select from selected 表示下一次选择的节点和当前选中的节点的交集会成为下一次选中的节点（越选越少）
5. 快捷键 `u` 选择节点时的维度限制
### 图布局
1. 双击节点，将节点居中，按住鼠标中键移动，绕z轴旋转
2. 快捷键 `z` 开关布局动画，由于布局计算非常耗时，因此设置这个开关。
3. 快捷键 `2` 2d布局
4. 快捷键 `3` 3d布局
5. 快捷键 `t + +` 增加布局温度，布局温度越高，布局速度越快，但也会导致节点抖动幅度越大
6. 快捷键 `t + -` 减少布局温度
7. 快捷键 `w + +` 增加选中的节点所组成的子图的布局权重，权重越大，布局月紧凑
8. 快捷键 `w + -` 减少选中的节点所组成的子图的布局权重
9. 快捷键 `ctrl + alt + w` 恢复未选中的节点布局权重
10. 快捷键 `ctrl + v` 固定选中的节点的位置
11. 快捷键 `shift + v` 取消固定选中的节点的位置
12. 快捷键 `ctrl + alt + v` 取消固定未选中的节点的位置
13. 快捷键 `ctrl + x` 固定选中的节点的x坐标
14. 快捷键 `shift + x` 取消固定选中的节点的x坐标
15. 快捷键 `ctrl + alt + x` 取消固定未选中的节点的x坐标
16. 快捷键 `ctrl + y` 固定选中的节点的y坐标
17. 快捷键 `shift + y` 取消固定选中的节点的y坐标
18. 快捷键 `ctrl + alt + y` 取消固定未选中的节点的y坐标
19. 快捷键 `ctrl + b` 限制选中的节点的位置范围
20. 快捷键 `shift + b` 取消限制选中的节点的位置范围
21. 快捷键 `ctrl + alt + b` 取消限制未选中的节点的位置范围
22. 快捷键 `ctrl + j` 聚合选中的节点
23. 快捷键 `shift + j` 取消聚合选中的节点
24. 快捷键 `ctrl + alt + j` 取消聚合未选中的节点
25. 快捷键 `x + l` 自动将出度和入度都是一的节点按照X坐标聚合
26. 快捷键 `y + l` 自动将出度和入度都是一的节点按照Y坐标聚合
27. 快捷键 `j + l` 自动聚合出度和入度都是一的节点
28. 快捷键 `b + c` 自动按照类来限制所有节点的位置范围
29. 快捷键 `b + m` 自动按照函数来限制所有节点的位置范围
30. 快捷键 `t + u` 树状布局向上
31. 快捷键 `t + d` 树状布局向下
### 图样式(大小与颜色)
1. 快捷键 `shift + k` 显示隐藏节点文字，（选中的节点旁会显示对应的文字）   
2. 快捷键 `shift + t` 显示隐藏节点详细信息，（鼠标悬浮在节点上方时会有节点详细信息）   
3. 快捷键 `ctrl + shift + b` 显示隐藏节点的位置边界     
4. 快捷键 `k + +` 节点文字变大
5. 快捷键 `k + -` 节点文字变小
6. 快捷键 `ctrl + +` GUI文字变大
7. 快捷键 `ctrl + -` GUI文字变小 
8. 快捷键 `o + +` 节点变大
9. 快捷键 `o + -` 节点变小
10. 快捷键 `i + +` 连线变粗
11. 快捷键 `i + -` 连线变细
12. 快捷键 `N + +` 未选中的节点变的更不透明
13. 快捷键 `N + -` 未选中的节点变的更透明
14. 快捷键 `M + +` 选中的节点变的更不透明 
15. 快捷键 `M + -` 选中的节点变的更透明 
16. 快捷键 `h` 给选中的节点选择颜色，会覆盖节点之前的颜色
17. 快捷键 `ctrl + h` 给所有节点自动上色，不会覆盖节点之前的颜色
18. 快捷键 `ctrl + alt + h` 清除未选中的节点的颜色
### 删除节点和边
快捷键 `ctrl + /` 删除选中的节点     
快捷键 `ctrl + alt + /` 删除未选中的节点。     
删除的节点可以使用快捷键 `ctrl + f` 恢复     
快捷键 `ctrl + r` Transitive Reduction 
### 探索模式
使用正则搜索一次后，通过对搜索结果的阅读，会让你对代码有新的认识，因此会产生新的搜索需求。如果这新的搜索需求是针对图中的某些节点，那么不需要回到正则编辑面板，直接选中这些节点后，使用下面的快捷键进行二次搜索。    
快捷键 `alt + .` 选择正则，并以选中的节点为始端进行二次搜索   
快捷键 `alt + ,` 选择正则，并以选中的节点为末端进行二次搜索    

### 保存到下一轮
快捷键 `ctrl + d` 将选中的节点保存为正则**普通字符**，用以下一轮的正则搜索。

### 保存恢复图
快捷键 `ctrl + s` 保存图到硬盘。    
快捷键 `ctrl + o` 恢复保存过的图。   
快捷键 `shift + o` 删除保存过的图。   
你保存的图以文字的形式保存在硬盘中，路径是：     
```
./build/graph/...
```
复制此路径下的文件给别人可以分享你保存的图

## 项目方案
|用到的功能|三方工具|
|---|---|
|源码解析|[antlr4](https://github.com/antlr/antlr4)|
|GUI|[imgui](https://github.com/ocornut/imgui)|
|正则搜索|[re2](https://github.com/google/re2) + [swipl](https://github.com/SWI-Prolog/swipl-devel)|
|绘制搜索结果|[threepp](https://github.com/markaren/threepp)|
|力导布局与其他图算法|[igraph](https://github.com/igraph/igraph)|

