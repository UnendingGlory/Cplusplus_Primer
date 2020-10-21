#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MyString
{
public:
    static size_t ccons;
    static size_t CCtor; //统计调用拷贝构造函数的次数
//    static size_t CCtor; //统计调用拷贝构造函数的次数
public:
    // 构造函数
   MyString(const char* cstr=0){
       ++ccons;
       if (cstr) {
          m_data = new char[strlen(cstr)+1];
          strcpy(m_data, cstr);
       }
       else {
          m_data = new char[1];
          *m_data = '\0';
       }
   }

   // 拷贝构造函数
   MyString(const MyString& str) {
       CCtor ++;
       m_data = new char[ strlen(str.m_data) + 1 ];
       strcpy(m_data, str.m_data);
   }

   // 拷贝赋值函数 =号重载
   MyString& operator=(const MyString& str){
       if (this == &str) // 避免自我赋值!!
          return *this;

       delete[] m_data;
       m_data = new char[ strlen(str.m_data) + 1 ];
       strcpy(m_data, str.m_data);
       return *this;
   }

   ~MyString() {
       delete[] m_data;
   }

   char* get_c_str() const { return m_data; }
private:
   char* m_data;
};
size_t MyString::CCtor = 0;
size_t MyString::ccons = 0;

int main()
{
    vector<MyString> vecStr;
    vecStr.reserve(1000); //先分配好1000个空间，不这么做，调用的次数可能远大于1000
    for(int i = 0; i < 1000; i++)
    {
        // MyString调用构造函数先生成临时对象
        // 然后vecStr尾部元素生成新对象再调用拷贝构造函数，拷贝这些对象
        // 所以最后输出拷贝构造函数调用次数是1000
        // 如果换成emplace_back，则是0
        // 因为emplace_back直接在vector的尾部用构造函数，不需要拷贝
        // vecStr.push_back("hello");
        // vecStr.emplace_back("hello");
        // 但是如果写成MyString("hello")，则emplace_back也会调用1000次拷贝构造
        // 这个时候emplace_back直接在vector的尾部用拷贝构造函数
        // vecStr.push_back(MyString("hello"));
        vecStr.emplace_back(MyString("hello"));
    }
    cout << MyString::CCtor << endl;
    cout << MyString::ccons << endl;
}