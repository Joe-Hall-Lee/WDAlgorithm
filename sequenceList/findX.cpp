/*
	线性表递增有序存放，设计一算法，用最少的时间查找值为 x 的元素，
	若找到则将其与后续元素位置相交换，否则，插入使其仍然有序。
	分析：
		题目告知这是一个递增有序表，要使时间最少，可以采取折半查找的方式，这样比顺序查找省时。

*/
#include <iostream>
using namespace std;
int n = 9;
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void findX(int a[], int x)
{
	int left, right, mid;
	left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			break;
		else if (a[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (a[mid] == x && mid != n - 1)
	{
		int t = a[mid];
		a[mid] = a[mid + 1];
		a[mid + 1] = t;
	}
	int i;
	if (right < left)
	{
		for (i = n - 1; i > right; i--)
			a[i + 1] = a[i];
		a[i + 1] = x;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	cout << endl;
	findX(a, 7);
	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}