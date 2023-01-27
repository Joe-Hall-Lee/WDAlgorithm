/*
	将两个有序顺序表合并成一个新的顺序表，并由函数返回新的结果顺序表。
	分析：
		手动开辟一个数组空间，其大小要大于等于原始两个数组的长度，之后进行遍历，依次取较小值赋给新数组。
*/
#include <iostream>
using namespace std;
#define Max 50
struct sqlist
{
	int data[Max];
	int length;
};

bool merge(sqlist a, sqlist b, sqlist &c)
{
	if (c.length < a.length + b.length)
		return false;
	int i = 0, j = 0, k = 0;
	while (i < a.length && j < b.length)
	{
		if (a.data[i] <= b.data[j])
			c.data[k++] = a.data[i++];
		else
			c.data[k++] = b.data[j++];
	}
	while (i < a.length)
		c.data[k++] = a.data[i++];
	while (j < b.length)
		c.data[k++] = b.data[j++];
	c.length = a.length + b.length;
	return true;
}

int main()
{
	sqlist a = {{2, 3, 4, 6, 7}, 5};
	sqlist b = {{3, 4, 4}, 3};
	sqlist c;
	c.length = 8;
	for (int i = 0; i < a.length; i++)
		cout << a.data[i] << " ";
	cout << endl;
	for (int i = 0; i < b.length; i++)
		cout << b.data[i] << " ";
	cout << endl;
	if (!merge(a, b, c))
		cout << "合并错误" << endl;
	else
	{
		for (int i = 0; i < c.length; i++)
			cout << c.data[i] << " ";
	}
	cout << endl;
	return 0;
}