#include <stdlib.h>
#include <stdio.h>
#include <vector>
#define ERROR 34567890  //一个不可能的数，用于错误返回
using namespace std;

template<typename comparable>
class BinaryHeap
{
public:
	BinaryHeap() { currentSize = array.size(); };
	BinaryHeap(const vector<comparable>& items);

	bool isEmpty() const;
	void insert(const comparable& x);
	comparable top() const;
	void deleteMin() ;
	void makeEmpty();
private:
	int currentSize;							//堆中元素个数
	vector<comparable> array;					//堆的数组
	void swap(comparable& x1, comparable& x2);
	bool isMinHeap(int position) const;
	int down_heap(int position);
};


template<typename comparable>
inline BinaryHeap<comparable>::BinaryHeap(const vector<comparable>& items)
{
	currentSize = 0;
	if (!items.empty())
	{
		vector<comparable>::const_iterator iter = items.begin();
		for (; iter != items.end(); iter++)
		{
			insert(*iter);
		}
	}
}

template<typename comparable>
inline bool BinaryHeap<comparable>::isEmpty() const
{
	if (currentSize == 0)
		return true;
	return false;
}

template<typename comparable>
inline void BinaryHeap<comparable>::insert(const comparable & x)
{
	array.push_back(x);
	int size = ++currentSize;
	if (size == 1)
		return;
	if (x >= array[size / 2 - 1])
		return;
	else
	{
		//size = size / 2;
		while ((size / 2) > 0 && array[size - 1] < array[size / 2 - 1])
		{
			swap(array[size - 1], array[size / 2 - 1]);
			size = size / 2;
		}
	}
}

template<typename comparable>
inline comparable BinaryHeap<comparable>::top() const
{
	if (isEmpty())
		return ERROR;
	return array[0];
}

template<typename comparable>
inline void BinaryHeap<comparable>::deleteMin()
{
	if (isEmpty())
		return;
	else if (currentSize == 1)
	{
		array.clear();
		currentSize = 0;
		return;
	}
	else
	{
		array[0] = array[currentSize - 1];
		array.pop_back();
		currentSize--;
		int size = 1;
		bool is = isMinHeap(size);
		while (!isMinHeap(size))
		{
			size = down_heap(size);
		}
	}
}

template<typename comparable>
inline void BinaryHeap<comparable>::makeEmpty()
{
	currentSize = 0;
	array.clear();
}

template<typename comparable>
inline void BinaryHeap<comparable>::swap(comparable& x1, comparable& x2)
{
	x1 ^= x2;
	x2 ^= x1;
	x1 ^= x2;
}

template<typename comparable>
inline bool BinaryHeap<comparable>::isMinHeap(int position) const
{
	if (currentSize >= position * 2 + 1)
	{
		if (array[position - 1] > array[position * 2 - 1] <= array[position * 2] ? array[position * 2 - 1] : array[position * 2])
			return false;
		return true;
	}
	else if (currentSize >= position * 2)
	{
		if (array[position - 1] > array[position * 2 - 1])
			return false;
		return true;
	}
	else
		return true;

}

template<typename comparable>
inline int BinaryHeap<comparable>::down_heap(int position)
{
	if (currentSize >= position * 2 + 1)
	{
		int size = array[position * 2 - 1] <= array[position * 2] ? position * 2 : position * 2 + 1;
		swap(array[position - 1], array[position * 2 - 1] <= array[position * 2] ? array[position * 2 - 1] : array[position * 2]);
		return size;
	}
	else
	{
		swap(array[position - 1], array[position * 2 - 1]);
		return position * 2;
	}
}
