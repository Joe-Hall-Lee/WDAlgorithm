/*
	已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为 i 和 j 的两个结点的最近的公共祖先结点。
	分析：
		利用数组存储一棵二叉树，一般来说我们用这种方式存储一棵完全二叉树，不浪费空间。
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