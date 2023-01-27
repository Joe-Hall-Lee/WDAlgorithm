/*
	设有一棵满二叉树（所有结点值均不同），已知其先序序列为 pre，设计一个算法求其后序序列 post。
	分析：
		1．找出先序序列的根结点，将其放入后序序列数组末尾；
		2．因为满二叉树总是对半分的，将根结点之后的节点分成左右两堆，再分别执行上一步；
		3．直至全部处理完。
*/
#include <iostream>
using namespace std;

// 递归交换过程
void preToPost(char *arrPre, char *arrPost, int l1, int h1, int l2, int h2)
{
	// l1、h1、l2、h2 代表 arrPre 和 arrPost 的起点和末尾
	int half; // 左右子树临界
	if (l1 <= h1)
	{
		half = (h1 - l1) / 2;
		*(arrPost + h2) = *(arrPre + l1);
		preToPost(arrPre, arrPost, l1 + 1, l1 + half, l2, l2 + half - 1); // 左边
		preToPost(arrPre, arrPost, l1 + half + 1, h1, l2 + half, h2 - 1); // 右边
	}
}

// 主函数，测试
int main()
{
	char arrPre[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'}, arrPost[7];
	preToPost(arrPre, arrPost, 0, 6, 0, 6);
	for (int i = 0; i < 7; i++)
		printf("%c ", *(arrPost + i));
	return 0;
}