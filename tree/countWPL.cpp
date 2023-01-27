/*
	二叉树的带权路径长度（WPL）是二叉树中所有叶结点的带权路径长度之和。给定一棵二叉树T，采用二叉链表存储，结点结构为
	{left, weight, right}。请试设计求T的WPL的算法。
	分析：
		求带权路径长度，既需要知道叶结点的权值，也需要知道其经过的路径，可以设置一个变量 deep 代表深度，也就是
		路径长度，设置一个静态变量 ans 累加带权路径，会使用到递归。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
	// 结点的值
	char weight;
	// 左右孩子指针
	struct treenode *lchild, *rchild;
} treenode, *tree;

// 建树
void buildtree(tree &t) // 建立一棵二叉树
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
		t->weight = ch;
		// 初始化
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归赋值
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 计算WPL
int countWPL(tree t, int deep)
{
	// 静态变量，存储结果值并在函数末尾返回
	static int ans = 0; // 设置静态变量
	// 若是叶子结点，累加值
	if (!t->lchild && !t->rchild)
		ans += (deep * (t->weight - '0')); // 计算带权路径
	// 若左子树不为空，递归遍历左子树找叶子结点同时层数 + 1
	if (t->lchild)
		countWPL(t->lchild, deep + 1); // 左子树
	// 若右子树不为空，递归遍历右子树找叶子结点同时层数 + 1
	if (t->rchild)
		countWPL(t->rchild, deep + 1); // 右子树
	return ans;
}

// 主函数测试
int main()
{
	tree t;
	buildtree(t);
	cout << countWPL(t, 0) << endl;
	return 0;
}