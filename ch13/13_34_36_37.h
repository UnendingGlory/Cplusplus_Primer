// 定义和实现应该分开较宜
#ifndef CH_13_34_36_37_H
#define CH_13_34_36_37_H
#include <string>
#include <set>

using std::string; using std::set;

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message &, Message &);
public:
    // folders被隐式初始化为空集合
    explicit Message(const string &str = "") : contents(str) {}
    // 拷贝控制成员
    Message(const Message &);
    // 拷贝赋值运算符
    Message &operator=(const Message &);

    ~Message();
    // 从给定Folder集合中添加/删除本Message
    void save(Folder &);
    void remove(Folder &);

    // 向folders中添加/删除一个给定的Folder*
    void add_folder(Folder *);
    void delete_folder(Folder *);
    
private:
    string contents; // 消息文本
    set <Folder*> folders; // 包含此消息的Folder集合，初始化为空集合
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void swap(Message &, Message &);

class Folder{
    friend void swap(Folder &, Folder &);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    // 添加一条Message
    void addMsg(Message *);
    // 删除一条Message
    void remMsg(Message *);

private:
    // 该Folder目录下包含的Message
    set<Message*> messages;
    void add_to_messages(const Folder &);
    void remove_from_messages();
};


void swap(Folder &, Folder &);

#endif