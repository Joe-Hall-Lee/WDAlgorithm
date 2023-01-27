/*
	写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法。
	分析：
		在后序序列中，若结点 p 有右子女，则右子女是其前驱，若无右子女而有左子女，则左子女是其前驱。若结点 p 左右子女均无，
		设其中序左线索指向某祖先结点 f（p 是 f 右子树中按中序遍历的第一个结点），若 f 有左子女，则其左子女是结点 p 在后序中的前驱；
		若f无左子女，则顺其前驱找双亲的双亲，一直找到双亲有左子女（此时左子女是p的前驱）。还有一种情况，若 p 是中序遍历的第
		一个结点，则结点 p 在中序和后序下均没有前驱。
*/
#include <iostream>
using namespace std;
// 线索二叉树结点结构体
typedef struct treenode
{
	// 结点的值
	char data;
	// 左右孩子指针
	struct treenode *lchild, *rchild;
	// ltag、rtag
	int ltag, rtag;
} treenode, *tree;

// 建树，赋值结点
void buildtree(tree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		// 分配内存
		t = (treenode *)malloc(sizeof(treenode));
		// 赋值给结点
		t->data = ch;
		// 初始化
		t->lchild = NULL;
		t->rchild = NULL;
		t->ltag = t->rtag = 0;
		// 递归赋值
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 遍历二叉树的保留的前驱结点
tree pre;

// 中序线索化
void zx(tree &t)
{
	// 递归的条件
	if (t)
	{
		// 向左延伸
		zx(t->lchild);
		if (!t->lchild) // 左孩子空
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		else
			t->ltag = 0;
		if (pre && !pre->rchild) // 没有右孩子
		{
			pre->rtag = 1;	 // 前驱结点有后继结点
			pre->rchild = t; // 后继结点指向当前
		}
		pre = t; // 更新前驱结点
		zx(t->rchild);
	}
}

// 找后继的前驱结点
tree inPostPre(tree t, treenode *p) // 返回前驱结点
{
	// 结果指针
	treenode *q;
	// 该结点有右孩子，结果就是右孩子
	if (p->rtag == 0)
		return p->rchild;
	// 该结点没有右孩子的情况下，有左孩子，结果就是左孩子
	else if (p->ltag == 0)
		return p->lchild;
	// 该结点的前驱为空，即为中序第一个结点，无后序前驱
	else if (!p->lchild)
		q = NULL;
	// 其它
	else
	{
		// 不断沿着线索找祖先结点
		while (p->lchild && p->ltag == 1) // 如果该祖先没有左孩子，继续找前驱
			p = p->lchild;
		// 若找到祖先结点，且有左孩子，结果就是左孩子
		if (p->ltag == 0)
			q = p->lchild;
		// 最后就是没有后序前驱
		else
			q = NULL;
	}
	return q;
}

// 主函数，测试
int main()
{
	tree t;
	buildtree(t);
	zx(t);										   // 中序遍历建立线索
	cout << inPostPre(t, t->rchild)->data << endl; // 手动指定一个结点
	return 0;
}