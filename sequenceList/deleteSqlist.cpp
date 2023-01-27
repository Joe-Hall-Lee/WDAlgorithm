/*
	从顺序表中删除在给定值 s 与 t 之间的值，若给定区间不合理或顺序表为空，则显示错误信息并退出。
*/
#include <iostream>
using namespace std;
#define Max 50
struct sqlist
{
	int a[Max] = {4, 1, 2, 5, 0, 0, 3};
	int length = 7;
};

bool deleteSqlist(sqlist &L, int s, int v)
{
	if (L.length == 0 || s >= v)
		return false;
	int k = 0;
	bool flag = false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.a[i] >= s)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
		return false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.a[i] >= s && L.a[i] <= v)
			k++;
		else
			L.a[i - k] = L.a[i];
	}
	L.length = L.length - k;
	return true;
}

int main()
{
	sqlist L;
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	cout << endl;
	if (!deleteSqlist(L, 3, 5))
		cout << "错误" << endl;
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	return 0;
}