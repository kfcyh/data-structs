#pragma once
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAXSIZE 10

template<typename T>
class OrderStack
{
public:
	OrderStack() :_index(-1) {};		//初始化空表
	~OrderStack() {};

	bool empty() const;			        //堆栈为空则返回真
	void pop();					            //移除栈顶元素
	void push(T value);			        //在栈顶增加元素
	int size() const;			          //返回栈中元素数目
	T top() const;				          //返回栈顶元素

private:
	int _index;					            //游标
	T data[MAXSIZE];			          //数组容量为MAXSIZE
};

template<typename T>
inline bool OrderStack<T>::empty() const //判断是否空栈
{
	if (_index == -1)
		return true;
	return false;
}

template<typename T>
inline void OrderStack<T>::pop() //出栈
{
	if (_index == -1)
		return;
	_index--;
}

template<typename T>
inline void OrderStack<T>::push(T value) //入栈
{
	if (_index == MAXSIZE - 1)
		return;
	data[++_index] = value;
}

template<typename T>
inline int OrderStack<T>::size() const //返回栈元素个数
{
	return _index + 1;
}

template<typename T>
inline T OrderStack<T>::top() const //返回栈顶元素
{
	if (_index == -1)
		return 0;
	return data[_index];
}
