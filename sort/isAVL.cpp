/*
	利用二叉树遍历的思想编写一个判断二叉树是否是二叉平衡树的算法。
	分析：
		采取后序遍历来完成该算法，因为后序遍历不会含有重复计算。
		对每一个结点进行判断，如果左右子树均平衡且左右子树高度差小于等于1，则该结点平衡。
*/
#include <iostream>
using namespace std;
// 树结点的存储结构
typedef struct treenode
{
	// 结点值
	char data;
	// 左右孩子指针
	struct treenode *lchild, *rchild;
} treenode, *tree;

// 建树
void buildtree(tree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		// 分配空间
		t = (treenode *)malloc(sizeof(treenode));
		// 赋值
		t->data = ch;
		// 初始化
		t->lchild = NULL;
		t->rchild = NULL;
		//递归赋值
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 后序遍历，判断是否是平衡二叉树
void isAVL(tree t, int &ba, int &h)
{
	// 左右子树的高度，平衡因子变量
	int h1, h2, b1, b2;
	// 空树，高度为0，平衡因子为1
	if (!t)
	{
		h = 0;
		ba = 1;
	}
	// 只有一个根结点，高度为1，平衡因子为1
	else if (!t->lchild && !t->rchild)
	{
		h = 1;
		ba = 1;
	}
	else
	{
		// 递归判断左子树
		isAVL(t->lchild, b1, h1);
		// 递归判断右子树
		isAVL(t->rchild, b2, h2);
		// 到根这里，更新树高
		h = max(h1, h2) + 1;
		// 判断左右子树高度绝对值之差
		if (abs(h1 - h2) <= 1)
			ba = b1 && b2;
		else
			ba = 0;
	}
}

int main()
{
	tree t;
	buildtree(t);
	int ba, h;
	isAVL(t, ba, h);
	cout << ba << endl;
	return 0;
}