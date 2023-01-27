/*
	试设计判断两棵二叉树是否相似的算法。所谓二叉树 T1 和 T2 相似，指的是 T1 和 T2 都是空的二叉树或都只有一个根结点；
	或 T1 的左子树和 T2 的左子树是相似的，且 T1 的右子树和 T2 的右子树是相似的。
	分析：
		采取递归来处理。
*/
#include <iostream>
using namespace std;
// 树结点结构体
typedef struct treenode
{
	// 结点的值
	char data;
	// 左右孩子指针
	struct treenode *lchild, *rchild;
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
		// 赋值
		t->data = ch;
		// 左右孩子置空
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归赋值左右子树
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 递归比较左右子树：空 + 空 = 0，空 + 非空 = 0
int isSimilar(tree t1, tree t2)
{
	int left, right;
	if (!t1 && !t2) // t1、t2都是空的二叉树
		return 1;
	else if (!t1 || !t2) // t1、t2只有一个为空，则不相似
		return 0;
	else
	{
		left = isSimilar(t1->lchild, t2->lchild);
		right = isSimilar(t1->rchild, t2->rchild);
		return left && right; // 左右子树均相似，才相似
	}
}

// 主函数，测试
int main()
{
	tree t1, t2;
	buildtree(t1);
	buildtree(t2);
	cout << isSimilar(t1, t2) << endl;
	return 0;
}