#ifndef CH_16_12_BLOB_H
#define CH_16_12_BLOB_H

#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <exception>

using std::string; using std::vector;

template <typename> class StrBlobPtr;

// Blob不再针对String，而是一个类模板
template <typename T>
class Blob
{
	// 同一个类型实例化的才能是友元
	friend class StrBlobPtr<T>;
public:
	using value_type = T;
    using typename size_type = vector<T>::size_type;

    Blob();
    Blob(std::initializer_list<T> il1);

    size_type size() const { return data->size(); }
    bool empty() const {return data->empty();}

    void push_back(const T &t) { data->push_back(t); }
    void pop_back();

	// 定义常量和非常量版本
    T& operator[](size_type i);
	const T& operator[](size_type i) const;

    T &back();
	const T&back() const;

private:
    // 多个Blob共享vector
    std::shared_ptr<vector<T>> data;

    // 如果data[i]不合法，则抛出一个异常，msg为异常信息
    void check(size_type i, const string &msg) const;
};

// constructors, instantiation
template <typename T>
Blob<T>::Blob() : data(std::make_shared<vector<T>>()){}

// initializer constructor
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il1) : 
	data(std::make_shaerd<<vector<T>>(il1)) {}

// check
template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

// back of Blob
template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop on empty StrBlob");
    data->pop_back();
}
#endif