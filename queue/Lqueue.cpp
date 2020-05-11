/***********链队列***********/
#include <cstdlib>

template<typename T>
struct ListNode {
	T m_nValue;  //储存数据
	struct ListNode *m_pNext;  //指向后继
};

template<typename T>
class Lqueue
{
public:
	Lqueue();
	~Lqueue() {};

	T back()const;	 //返回最后一个元素
	bool empty()const;	 //如果队列空则返回真
	T front()const;		//返回第一个元素
	void pop();		//删除第一个元素
	void push(T value);		//在末尾加入一个元素
	int size()const;	//返回队列中元素的个数
private:
	ListNode<T>* pFront;   //头指针，一直指向头结点，它的后继节点若存在则为队头
	ListNode<T>* pRear;   //尾指针，若不指向头结点则指向队尾
	int _size;   //队长度
};

template<typename T>
inline Lqueue<T>::Lqueue()
{
	pFront = pRear = (ListNode<T>*)new ListNode<T>;	//初始化空队列，头指针和尾指针都指向头结点
	_size = 0;	//长度为0
}

template<typename T>
inline T Lqueue<T>::back() const
{
	if (pFront == pRear)
		return 0;
	return pRear->m_nValue;
}

template<typename T>
inline bool Lqueue<T>::empty() const
{
	if (pFront == pRear)
		return true;
	return false;
}

template<typename T>
inline T Lqueue<T>::front() const
{
	if (pFront == pRear)
		return 0;
	return pFront->m_pNext->m_nValue;
}

template<typename T>
inline void Lqueue<T>::pop()
{
	if (pFront == pRear)
		return;
	ListNode<T>* r = pFront->m_pNext;//暂存队头节点
	pFront->m_pNext = pFront->m_pNext->m_pNext;//将原队头节点后继节点赋为队头
	if (r == pRear) //若队头也是队尾则将头指针与尾指针指向头结点
		pRear = pFront;
	delete r; //删除队头
	_size--;
}

template<typename T>
inline void Lqueue<T>::push(T value)
{
	pRear->m_pNext = (ListNode<T>*)new ListNode<T>;//新分配节点
	pRear = pRear->m_pNext;//将新分配节点设为新队尾
	pRear->m_nValue = value;
	pRear->m_pNext = nullptr;//新队尾指向空
	_size++;
}

template<typename T>
inline int Lqueue<T>::size() const
{
	return _size;
}

