/*
	设一个二叉树各结点的值互不相同，其先序遍历序列和中序遍历序列分别存于两个一维数组 A、B 中，试编写算法建立该二叉树的二叉链表。
	分析：
		这是一个典型的已知中序和先序求二叉树的案例，具体实现步骤如下：
		1．先根据先序序列确定树的根结点。
		2．根据根结点在中序序列中划分出二叉树的左右子树包含哪些结点，然后根据左右子树结点在先序序列中的次序确定子树的
		的根结点，即回到步骤一。
		如此重复，直到每棵子树仅有一个结点为止。
*/
#include <iostream>
using namespace std;
typedef struct treenode
{
	char data;
	struct treenode *lchild, *rchild;
} treenode, *tree;

tree biTreeFromPreAndIn(char *arrIn, char *arrPre, int l1, int h1, int l2, int h2)
{
	// l1、h1 为中序的第一个和最后一个结点下标，l2、h2 为先序的第一个和最后一个结点
	int llen, rlen, i; // 左子树、右子树长度
	tree root = (tree)malloc(sizeof(treenode));
	root->data = arrPre[l2];
	for (i = l1; arrIn[i] != root->data; i++)
		;		   // 找到根结点在中序序列的位置
	llen = i - l1; // 记录左边结点个数
	rlen = h1 - i; // 记录根结点右边结点个数
	if (llen)
		root->lchild = biTreeFromPreAndIn(arrIn, arrPre, l1, l1 + llen - 1, l2 + 1, l2 + llen);
	else
		root->lchild = NULL;
	if (rlen)
		root->rchild = biTreeFromPreAndIn(arrIn, arrPre, h1 - rlen + 1, h1, h2 - rlen + 1, h2); // 把右边的序列看作一个新的继续找根结点
	else
		root->rchild = NULL;
	return root;
}

void disp(tree t)
{
	if (t)
	{
		disp(t->lchild);
		disp(t->rchild);
		cout << t->data << " ";
	}
}

int main()
{
	char a[] = {'A', 'B', 'D', 'E', 'C', 'F'}; // 先序序列
	char b[] = {'D', 'B', 'E', 'A', 'F', 'C'}; // 中序序列
	tree root = biTreeFromPreAndIn(b, a, 0, 5, 0, 5);
	cout << "后序序列为：" << endl;
	disp(root);
	return 0;
}