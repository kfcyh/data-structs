#include "LinkList.h"

LinkList::LinkList()
{
	pHead = nullptr;
	pEnd = nullptr;
	_size = 0;
}

LinkList::LinkList(unsigned int count, int value)
{
	if (count <= 0)
		return;
	_size = 0;
	pHead = (pLinklist)new ListNode;
	pHead->m_nValue = value;
	pHead->m_pNext = nullptr;
	_size = count;
	pLinklist p = pHead;
	pLinklist r = nullptr;
	for (int k = 0; k < _size-1; k++)
	{
		r = (pLinklist)new ListNode;
		r->m_nValue = value;
		r->m_pNext = nullptr;
		p->m_pNext = r;
		p = p->m_pNext;
	}
	pEnd = p;
}

LinkList::LinkList(const LinkList& L)
{
	if (L._size == 0)
	{
		LinkList();
		return;
	}
	_size = L._size;
	pLinklist p, r;
	p = L.pHead;
	pHead = (pLinklist)new ListNode;
	pHead->m_nValue = p->m_nValue;
	pHead->m_pNext = nullptr;
	r = pHead;
	for (int i = 0; i < _size - 1; i++)
	{
		p = p->m_pNext;
		pLinklist temp = (pLinklist)new ListNode;
		temp->m_nValue = p->m_nValue;
		temp->m_pNext = nullptr;
		r->m_pNext = temp;
		r = r->m_pNext;
	}
	pEnd = r;
}

LinkList::~LinkList()
{

}

bool LinkList::Empty() const
{
	return (pHead == nullptr) ? true : false;
}

unsigned int LinkList::size() const
{
	return _size;
}

void LinkList::ClearList()
{
	if (_size == 0)
		return;
	pLinklist r;
	while (pHead!=pEnd)
	{
		r = pHead;
		pHead = pHead->m_pNext;
		delete r;
		_size--;
	}
	r = pHead;
	pHead = pEnd = nullptr;
	delete r;
	_size--;
}

void LinkList::push_back(int value)
{
	pLinklist p = (pLinklist)new ListNode;
	p->m_nValue = value;
	p->m_pNext = nullptr;
	pEnd->m_pNext = p;
	pEnd = pEnd->m_pNext;
	_size++;
}

void LinkList::pop_back()					//删除尾节点
{
	pLinklist p = pHead;
	while (p->m_pNext!=pEnd)
	{
		p = p->m_pNext;
	}
	pEnd = p;
	p = p->m_pNext;
	delete p;
	pEnd->m_pNext = nullptr;
	_size--;
}

int LinkList::back() const				//返回尾节点值
{
	if (!pEnd)
	{
		return 0;
	}
	return pEnd->m_nValue;
}

int LinkList::front() const						//返回头节点值
{
	if (!pHead)
	{
		return 0;
	}
	return pHead->m_nValue;
}

int LinkList::GetElem(int i) const				//返回第i个位置的值，若i大于size返回0
{
	if (!pHead || i > _size)
	{
		return 0;
	}
	int count = 1;
	pLinklist p = pHead;
	while (count<i)
	{
		p = p->m_pNext;
		count++;
	}
	return p->m_nValue;
}
//void LinkList::DeleteElem(int i)					//删除第i个位置的值
//{
//	if (!pHead || i > _size)
//	{
//		return;
//	}
//	int count = 1;
//	pLinklist p = pHead;
//	while (count<i)
//	{
//		p = p->m_pNext;
//		count++;
//	}
//	return p->m_nValue;
//}
void LinkList::InsertElem(int i, int a)			//将a插入到第i个位置
{
	if (!pHead || i > _size || i <= 0)
	{
		return;
	}
	if (i == 1)
	{
		pLinklist r = (pLinklist)new ListNode;
		r->m_nValue = a;
		r->m_pNext = pHead;
		pHead = r;
		_size++;
		return;
	}
	int count = 1;
	pLinklist p = pHead;
	while (count < i - 1)
	{
		p = p->m_pNext;
		count++;
	}
	pLinklist r = (pLinklist)new ListNode;
	r->m_nValue = a;
	r->m_pNext = p->m_pNext;
	p->m_pNext = r;
	_size++;
}

pLinklist LinkList::Begin() const
{
	return pHead;
}

pLinklist LinkList::End() const
{
	return nullptr;
}

LinkList& LinkList::operator=(const LinkList& L)
{
	if (&L == this)
	{
		return *this;
	}
	if (L._size == 0)
	{
		LinkList();
		return *this;
	}
	_size = L._size;
	pLinklist p, r;
	p = L.pHead;
	pHead = (pLinklist)new ListNode;
	pHead->m_nValue = p->m_nValue;
	pHead->m_pNext = nullptr;
	r = pHead;
	for (int i = 0; i < _size - 1; i++)
	{
		p = p->m_pNext;
		pLinklist temp = (pLinklist)new ListNode;
		temp->m_nValue = p->m_nValue;
		temp->m_pNext = nullptr;
		r->m_pNext = temp;
		r = r->m_pNext;
	}
	pEnd = r;
	return *this;
}

/*************************迭代器************************/
LinkList_iterator::LinkList_iterator()
{
	_index = nullptr;
}

LinkList_iterator::LinkList_iterator(const pLinklist p)
{
	_index = p;
}

LinkList_iterator::~LinkList_iterator()
{

}

bool LinkList_iterator::operator==(const LinkList_iterator& rhs) const
{
	return _index == rhs._index;
}

bool LinkList_iterator::operator!=(const LinkList_iterator& rhs) const
{
	return _index != rhs._index;
}

LinkList_iterator& LinkList_iterator::operator++()	//前置
{
	_index = _index->m_pNext;
	return *this;
}
LinkList_iterator LinkList_iterator::operator++(int)	//后置
{
	LinkList_iterator temp = *this;
	_index = _index->m_pNext;
	return temp;
}

int LinkList_iterator::operator*() const
{
	return _index->m_nValue;
}
