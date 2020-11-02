#pragma once

#include <string>
#include <iostream>
#include <sstream>

// debug函数，定义一个模板，返回一个给定对象的string表示
template <typename T>
std::string debug_rep(const T& t)
{
	std::ostringstream ret;
	ret << t; // 使用T的输出运算符打印
	return ret.str();
}

// debug函数，定义一个函数，针对指针
template <typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer :" << p; // 指引指针本身的值
	if(p)
		ret << " " << debug_rep(*p); // 打印p指向的值
	else
		ret << "null pointer";
	return ret.str();
}