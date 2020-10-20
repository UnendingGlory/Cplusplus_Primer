#include "13_34_36_37.h"

void Message::save(Folder &f)
{
    // 将给定Folder添加到Folder列表中，表示本消息被该Folder引用
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

// 类的拷贝控制成员
// 拷贝一个Message类时，原对象和拷贝的对象在一个Folder中
// 但两者是不同的Message对象
// 所以我们必须遍历Folder指针的set，将包含所有该对象的Folder再包含左侧对象
void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)
    {
        f->addMsg(this);
    }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    this->add_to_Folders(m);
}

// a = b;
Message& Message::operator=(const Message &m)
{
    // 左侧对象被赋值了，所以所有包含该对象的Folders都该remove掉
    // 且先remove掉可以保证自赋值的正确性
    remove_from_Folders();
    // 处理拷贝
    contents = m.contents;
    folders = m.folders;
    // m中所有folders都添加this
    add_to_Folders(m);
    return *this;
}

// 当一个Message被销毁时，必须从指向此Message的Folder中删除t它
void Message::remove_from_Folders()
{
    for(auto f : folders)
    {
        f->remMsg(this);
    }
}

Message::~Message()
{
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    // 将每个消息的指针从它原来所在的Folder中删除
    for(auto f: lhs.folders) f->remMsg(&lhs);
    for(auto f: rhs.folders) f->remMsg(&rhs);

    // 交换contents和Folder指针set
    swap(lhs.folders, rhs.folders); // 使用swap(set&, set&)
    swap(lhs.contents, rhs.contents); // 使用swap(string&, string &)
    // swap过后将每个Message指针添加到新folder中
    for(auto f: lhs.folders) f->addMsg(&lhs);
    for(auto f: rhs.folders) f->addMsg(&rhs);
}

void Message::add_folder(Folder *f)
{
    folders.insert(f);
}

void Message::delete_folder(Folder *f)
{
    folders.erase(f);
}

// Folder Implementation

Folder::Folder(const Folder& f)
{
    add_to_messages(f);
}

// 将该目录添加到每一个message的folder set中去
void Folder::add_to_messages(const Folder &f)
{
    for(auto m : f.messages)
    {
        m->add_folder(this);
    }
}

// Folder a = b;
// 对于b中的每个目录下的message来说都添加了一个folder
// 所以在f的所有message中添加this
Folder& Folder::operator=(const Folder &f)
{
    remove_from_messages();
    messages = f.messages;
    add_to_messages(f);
    return *this;
}

// 析构时别忘了释放
Folder::~Folder()
{
    remove_from_messages();
}

void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

// 将该目录从每一个message的folder set中删掉
void Folder::remove_from_messages()
{
    for(auto m: messages)
    {
        m->delete_folder(this);
    }
}

// 为了避免外层不必要的拷贝，所以定义内置的swap
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;

    for(auto m: lhs.messages) m->delete_folder(&lhs);
    for(auto m: rhs.messages) m->delete_folder(&rhs);

    swap(lhs.messages, rhs.messages);
    for(auto m: lhs.messages) m->add_folder(&lhs);
    for(auto m: rhs.messages) m->add_folder(&rhs);
}

int main()
{
    return 0;
}