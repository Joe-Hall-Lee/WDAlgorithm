// ���Ա�ǰ�󻥻�
#include <iostream>
using namespace std;
#define Max 50
struct sqlist
{
	int a[Max] = {1, 2, 3, 4, 5, 6, 7};
	int length = 7;
};

void reverse(sqlist &L, int left, int right)
{
	for (int i = left; i <= (right + left) / 2; i++)
	{
		int t = L.a[i];
		L.a[i] = L.a[right + left - i];
		L.a[right + left - i] = t;
	}
}

void prin(sqlist L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	cout << endl;
}

void reverseList(sqlist &L, int m, int n)
{
	cout << "�������ã�" << endl;
	reverse(L, 0, m + n - 1);
	prin(L);
	cout << "ǰ n ������" << endl;
	reverse(L, 0, n - 1);
	prin(L);
	cout << "�� m �����ü����ս��" << endl;
	reverse(L, n, m + n - 1);
	prin(L);
}

int main()
{
	sqlist L;
	reverseList(L, 3, 4);
	return 0;
}