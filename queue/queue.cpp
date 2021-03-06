/**********顺序队列**********/
#include <cstdlib>
#define MAXSIZE 10  //循环队列容量
using namespace std;

template <typename T>
class queue
{
public:
	queue() :_front(0), _rear(0), _size(0) {};	//默认构造函数
	~queue() {}; //默认析构函数

	T back()const;	 //返回最后一个元素
	bool empty()const;	 //如果队列空则返回真
	T front()const;		//返回第一个元素
	void pop();		//删除第一个元素
	void push(T value);		//在末尾加入一个元素
	int size()const;	//返回队列中元素的个数

private:
	T data[MAXSIZE];	//队列数组
	int _front;	//队头游标
	int _rear;	//队尾游标
	unsigned int _size;	//队列元素数目
	const unsigned int capacity = MAXSIZE;	//队列容量=MAXSIZE-1
};

template<typename T>
inline T queue<T>::back() const
{
	if (_front == _rear)
		return 0;
	return data[(_rear - 1 + MAXSIZE) % MAXSIZE]
