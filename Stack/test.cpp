#include <iostream>
#include "LinkStack.h"
#include "OrderStack.h"
using namespace std;

int main()
{
	/*OrderStack<int> s;
	int num[] = { 1,2,3,4,5,6 };
	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		s.push(num[i]);
	}
	cout << "栈容量：" << s.size() << endl;
	while (!s.empty())
	{
		int value = s.top();
		printf("%d ", value);
		s.pop();
	}*/

	LinkStack<int> s;
	int num[] = { 1,2,3,4,5,6 };
	cout << "压栈：";
	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		s.push(num[i]);
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "栈容量：" << s.size() << endl << "出栈：";
	while (!s.empty())
	{
		int value = s.top();
		printf("%d ", value);
		s.pop();
	}

	getchar();
}

