/*
	����Ϊ n��ɾ��ֵΪ x ������Ԫ�أ�Ҫ��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)��
	������
		�� k ��¼ɾ��Ԫ�ظ�����һ�߱���˳���һ��ͳ�� k������������ x ��Ԫ����ǰŲ k ��λ�á�
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