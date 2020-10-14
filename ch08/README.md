#### Chapter 8 IO库
1. IO类：iostream, fstream（针对文件），sstream（针对字符串）

在这些类中，iostream分为istream，ostream

fstream分为ifstream，ofstream

sstream分为istringstream，ostringstream

2. IO类型不能拷贝或者赋值

因此如果函数返回IO类型对象，一般会返回引用

3. endl操纵符会显式刷新缓冲区（少用）并输出一个回车

flush会刷新缓冲区，但不加任何字符

4. 如果有一个函数接收一个ostream &参数，我们在调用这个函数时，可以传递给它一个ofstream对象，对istream和ifstream也是类似的

5. sstream头文件，string流，可以从string等读取数据，就像string是个IO流一样

istringstream，可以读一个字符串形成一个istringstream对象

ostringstream，可以存一个字符串

\>>和<<箭头的方向就是流的方向