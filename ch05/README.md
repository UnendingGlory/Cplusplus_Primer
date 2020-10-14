1. C++异常处理
try……catch语句
```C++
try
{
    program-statements
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```
exception类不可以赋初值
而throw其他异常类（在头文件stdexcept），如runtime_error等，必须赋初值，一般是一个字符串

```C++
throw runtime_error("Data must be a digit")
```
