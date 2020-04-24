#pragma once
#include <cstdlib>
#include <cstdio>
using namespace std;

/**********节点定义*********/
template<typename T>
struct ListNode
{
	T m_nValue;
	ListNode* m_pNext;
};
/**********链栈类**********/
template<typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
private:
	ListNode<T>* p_Top;			//栈顶指针
	int _size;					    //节点数量
public:
	bool empty() const;			//堆栈为空则返回真
	void pop();					    //移除栈顶元素
	void push(T value);			//在栈顶增加元素
	int size() const;			  //返回栈中元素数目
	T top() const;				  //返回栈顶元素
};

template<typename T>
LinkStack<T>::LinkStack()		//构造空栈
{
	_size = 0;
	p_Top = nullptr;
}

template<typename T>
LinkStack<T>::~LinkStack()
{
}

template<typename T>
inline bool LinkStack<T>::empty() const //判断栈是否空
{
	if (p_Top == nullptr)
		return true;
	return false;
}

template<typename T>
inline void LinkStack<T>::pop() //出栈
{
	if (p_Top == nullptr)		
		return;
	ListNode<T>* r = p_Top;
	p_Top = p_Top->m_pNext;
	delete r;
}

template<typename T>
inline void LinkStack<T>::push(T value) //入栈
{
	ListNode<T>* r = new ListNode<T>;
	r->m_nValue = value;
	r->m_pNext = p_Top;
	p_Top = r;
	_size++;
}

template<typename T>
inline int LinkStack<T>::size() const //返回栈元素个数
{
	return _size;
}

template<typename T>
inline T LinkStack<T>::top() const //返回栈顶元素
{
	if (!p_Top)
		return 0;
	return p_Top->m_nValue;
}
