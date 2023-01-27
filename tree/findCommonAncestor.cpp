/*
	��֪һ�ö�������˳��洢�ṹ���д洢�����һ���㷨�����ŷֱ�Ϊ i �� j ��������������Ĺ������Ƚ�㡣
	������
		��������洢һ�ö�������һ����˵���������ַ�ʽ�洢һ����ȫ�����������˷ѿռ䡣
*/
#include <iostream>
using namespace std;
struct Tree
{
	/* data */
	int data[12] = {-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, -6, -1};
};

int findCommonAncestor(Tree t, int i, int j)
{
	if (t.data[i] != -1 && t.data[j] != -1)
	{
		while (i != j)
		{
			if (i > j)
				i /= 2;
			else
				j /= 2;
		}
		return t.data[i];
	}
	return -1;
}

int main()
{
	Tree t;
	int ans = findCommonAncestor(t, 7, 10);
	cout << ans << endl;
	return 0;
}