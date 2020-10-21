#ifndef CH_13_44_47_H
#define CH_13_44_47_H

#include <memory>
#include <utility>

class String{
public:
    String() : String("") {}
    String(const char *);
    String(const String &);
    String& operator=(const String &);
    ~String();

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    // 去掉末尾换行0
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char *, char*> alloc_n_copy(const char *, const char *);
    void range_initializer(const char *, const char *);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

#endif