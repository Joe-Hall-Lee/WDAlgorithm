/*
	������˳�����ɾ���ڸ���ֵ s �� t ֮���ֵ�����������䲻�����˳���Ϊ�գ�����ʾ������Ϣ���˳���
*/
#include <iostream>
using namespace std;
#define Max 50
struct sqlist
{
	int a[Max] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9};
	int length = 12;
};

bool deletePoint(sqlist &L, int s, int v)
{
	if (s >= v || L.length == 0)
		return false;
	int ss = 0;
	bool flag = false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.a[i] >= s)
		{
			ss = i;
			flag = true;
			break;
		}
	}
	if (!flag)
		return false;
	int vv = 0;
	for (int i = ss; i < L.length; i++)
	{
		if (L.a[i] > v)
		{
			vv = i;
			break;
		}
	}
	int s1 = ss, v1 = vv;
	for (int i = vv; i < L.length; i++)
	{
		L.a[ss] = L.a[i];
		ss++;
	}
	L.length = L.length - (v1 - s1);
	return true;
}

int main()
{
	sqlist L;
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	cout << endl;
	if (!deletePoint(L, 3, 7))
		cout << "����" << endl;
	cout << "���Ա���Ϊ��" << L.length << endl;
	for (int i = 0; i < L.length; i++)
		cout << L.a[i] << " ";
	return 0;
}