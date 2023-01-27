/*
	以孩子兄弟链表为存储结构，请设计递归算法求树的高度。
	分析：
		如果只有根结点，那么高度为1，如果有左孩子，那么高度由左孩子的左子树和右子树决定，取其大者。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
	// 结点值
	char data;
	// 左孩子域、右兄弟域指针
	struct treenode *child, *rbro;
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
		t->child = NULL;
		t->rbro = NULL;
		// 递归赋值
		buildtree(t->child);
		buildtree(t->rbro);
	}
}

// 递归计算深度
int highOfTree(tree t)
{
	if (!t) // 递归的出口
		return 0;
	else
	{
		// 递归计算左孩子子树高度
		int l = highOfTree(t->child); // 记录左子树高度
		// 递归计算右兄弟子树高度
		int r = highOfTree(t->rbro); // 记录右兄弟的高度，注意这里high不能再加一，因为它们是兄弟，平级
		return max(l + 1, r);
	}
}

// 主函数测试
int main()
{
	tree t;
	buildtree(t);
	cout << highOfTree(t) << endl;
	return 0;
}