/*
	长度为 n，删除值为 x 的数据元素，要求时间复杂度为 O(n)，空间复杂度为 O(1)。
	分析：
		用 k 记录删除元素个数，一边遍历顺序表一边统计 k，并将不等于 x 的元素向前挪 k 个位置。
*/
#include <iostream>
using namespace std;
#define Max 50
struct SqList
{
	/* data */
	int a[Max] = {5, 2, 0, 1, 3, 1, 4, 1, 1, 4};
	int length = 10;
};

void delX(SqList &L, int x)
{
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.a[i] == x)
			k++;
		else
			L.a[i - k] = L.a[i];
	}
	L.length = L.length - k;
}

int main()
{
	SqList L;
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	cout << endl;
	delX(L, 1);
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	cout << endl;
	return 0;
}