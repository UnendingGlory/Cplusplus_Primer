#ifndef CH_16_12_BLOBPTR_H
#define CH_16_12_BLOBPTR_H

#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <exception>
#include "16_12_Blob.h"

using std::string; using std::vector;
using std::shared_ptr;

template <typename T>
	bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
	bool operator<(const Blob<T>&, const Blob<T>&);

template <typename T>
class BlobPtr
{
	// 重载==运算符和<运算符为友元
	friend operator==<T>(const Blob<T>&, const Blob<T>&);
	friend operator< <T>(const Blob<T>&, const Blob<T>&);

public:
    BlobPtr() : curr(0) {}
    // wptr指向Blob中的shared_ptr
    BlobPtr(const Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz){ }
    T& deref() const;

    BlobPtr& operator++(); // 前缀递增
	BlobPtr& operator--(); // 前缀递减

	BlobPtr& operator++(int);
	BlobPtr& operator--(int);

private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<T>> check(std::size_t, const string&) const;

    // 保存一个weak_ptr，意味着底层vector可能被销毁
    std::weak_ptr<vector<T>> wptr;

    // 在数组中的当前位置
    std::size_t curr;
};

// 检查下标是否合法，以及指针指向的vector是否存在
template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(std::size_t i, const string &msg) const
{
    // lock函数检查weak_ptr指向的对象是否存在，存在则返回一个shared_ptr
    auto ret = wptr.lock();
    if(!ret) throw std::runtime_error("unbound BlobPtr");
    if(i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

// 非重载版本，解引用dereference StrBlobPtr
template <typename T>
T& BlobPtr<T>::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p)是对象指向的vector
}

// 前缀自增
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

// 后缀自增
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this; // call the prefix increment to check
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--*this; // call the prefix decrement to check
    return ret;
}

template <typename T>
	bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
	{
		if (lhs.wptr.lock() != rhs.wptr.lock()) 
		{
			throw runtime_error("ptrs to different Blobs!");
		}
		return lhs.data == rhs.data;
	}

template <typename T>
	bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
	{
		if (lhs.wptr.lock() != rhs.wptr.lock()) 
		{
			throw runtime_error("ptrs to different Blobs!");
		}
		return lhs.data < rhs.data;
	}

#endif