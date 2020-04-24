/**************************************************************************************************
2020/03/25 Wednesday
作者：叶衡（华侨大学）

<链表节点结构体>：
	--int型数据成员
	--指向结构体的指针

<单链表（具有迭代器）封装类>：
构造函数：
	1.默认构造函数，构造空链表
	2.接受两个参数(int n,int m)，构造n个值为m的链表
	3.默认copy构造函数
私有数据成员：
	--头指针
	--尾指针
	--链表长度
成员函数：
	1.赋值构造函数
	2.检查链表是否为空，空返回true，否则返回false
	3.返回表长度
	4.清空链表
	5.将value插入到表尾
	6.删除尾节点
	7.返回尾节点值
	8.返回头节点值
	9.返回第i个位置的值，若i大于size返回0
	10.将a插入到第i个位置
	11.返回头节点位置
	12.返回尾节点的下一个位置
***************************************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
using namespace std;
#define ERROR 0
#define OK 1
typedef int Status;

/*********************************************链表节点*********************************************/
typedef struct ListNode{
	int m_nValue;
	struct ListNode *m_pNext;
}*pLinklist;
/**************************************************************************************************/

/*************************************************迭代器*******************************************/
class LinkList_iterator{
private:
	void check_integrity() const;
	pLinklist _index;
public:
	LinkList_iterator();
	LinkList_iterator(const pLinklist p);
	~LinkList_iterator();
public:
	bool operator==(const LinkList_iterator& rhs) const;	//判断this和rhs是否指向同一节点，是返回true,否返回false
	bool operator!=(const LinkList_iterator& rhs) const;	//判断this和rhs是否指向同一节点，否返回true,是返回false
	int operator*() const;									//提领该迭代器指向的值，即this->_index->m_nValue
	LinkList_iterator& operator++();						//前置++，使迭代器指向下一节点
	LinkList_iterator operator++(int);						//后置++，使迭代器指向下一节点
};
/*************************************************************************************************/

/*********************************************链表类**********************************************/
class  LinkList
{
	friend class LinkList_iterator;				//将LinkList_iterator声明为friend
public:
	typedef LinkList_iterator iterator;

	LinkList_iterator begin() const				//返回链表头节点位置
	{
		return LinkList_iterator(pHead);
	}

	LinkList_iterator end() const				//返回链表尾节点位置
	{
		return LinkList_iterator();
	}

public:											/*************构造函数************/
	 LinkList();								//构造空链表
	 LinkList(unsigned int count, int value);	//构造具有count个值为value的链表
	 LinkList(const LinkList& L);				//以另一个对象L构造
	~ LinkList();								//析构函数

private:										/*************数据成员************/
	pLinklist pHead;							//指向头节点指针
	pLinklist pEnd;								//指向尾节点指针
	unsigned int _size;							//链表长度

public:											/*************公有接口************/
	bool Empty() const;							//检查链表是否为空，空返回true，否则返回false
	unsigned int size() const;					//返回表长度
	void ClearList();							//清空链表
	void push_back(int value);					//将value插入到表尾
	void pop_back();							//删除尾节点
	int back() const;							//返回尾节点值
	int front() const;							//返回头节点值
	int GetElem(int i) const;					//返回第i个位置的值，若i大于size返回0
	void InsertElem(int i,int a);				//将a插入到第i个位置
	pLinklist Begin() const;					//返回头节点位置
	pLinklist End() const;						//返回尾节点的下一个位置
	LinkList& operator=(const LinkList& L);		//赋值构造函数
};
/***********************************************************************************************/


