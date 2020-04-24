#include "LinkList.h"

int main()
{
	LinkList L(3, 3);
	LinkList L2;
	L2 = L;
	L2.push_back(4);
	L2.push_back(5);
	L2.pop_back();
	L2.InsertElem(1, 7);
	//L2.ClearList();
	if (!L2.Empty())
	{
		cout << "链表长度：" << L2.size() << "\n" << "元素：";
		LinkList::iterator iter = L2.begin();
		while (iter != L2.end())
		{
			cout << *iter << " ";
			iter++;
		}
		cout << "\n" <<"首元素："<< L2.front() << " "<<"尾元素：" << L2.back();
	}
	getchar();
}
