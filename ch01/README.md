### Chapter 1 概述
1. C++文件后缀不仅有cpp，还有cc； C； cxx等
2. 文件重定向命令：Windows下  **xxx.exe**  <input_file> output_file 
>linux下也相同，xxx <input_file> output_file


3. 缓冲区 buffer，IO设备通常将输入输出数据保存在一个缓冲区中
 
4. 多行注释规范书写
```C++
/*
 *
 *
 */
```

源码函数注释编写：
```C++
/**
 *  @brief 对函数功能的简述
 *  @param __x 函数中出现过的变量说明
 *  @return 说明函数的返回
 *  other despcritions or notations
 */

/** 
 *  @note 提示点
 */
```

5. 预处理名字由预处理器提供而非编译器管理，调用时直接使用即可，由编译器管理的使用时才需要std::或者xxx::来声明

#include，#define都是预处理定义

在编译前，预处理阶段处理这些预处理定义
一些内置宏：

![981bd902a7af1cfc62ee9075e48c9e1e.png](../assets/ch01.png)
