/*
	���Ա���������ţ����һ�㷨�������ٵ�ʱ�����ֵΪ x ��Ԫ�أ�
	���ҵ����������Ԫ��λ���ཻ�������򣬲���ʹ����Ȼ����
	������
		��Ŀ��֪����һ�����������Ҫʹʱ�����٣����Բ�ȡ�۰���ҵķ�ʽ��������˳�����ʡʱ��

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