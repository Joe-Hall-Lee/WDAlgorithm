/*
	请设计一个算法，将给定的表达式树转换为等价的中缀表达式并输出。
	分析：
		采取中序遍历，进而输出该表达式，那么需要注意的点便是括号在哪里加，其中根结点处和叶子结点
		处不需要添加括号，其余情况在访问左子树前加左括号，访问右子树后添加右括号。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
	// 结点值
	char data;
	// 左右孩子的指针
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
		// 分配内存空间
		t = (treenode *)malloc(sizeof(treenode));
		// 赋值
		t->data = ch;
		// 初始化
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归赋值
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 转化函数
void putInExp(tree t, int deep)
{
	if (!t)
		return;
	if (!t->lchild && !t->rchild) // 若为叶结点，直接输出操作数
		cout << t->data;
	else
	{
		if (deep > 1)
			cout << "("; // 非根结点，添加左括号
		putInExp(t->lchild, deep + 1);
		cout << t->data;
		putInExp(t->rchild, deep + 1);
		if (deep > 1)
			cout << ")";
	}
}

// 主函数测试
int main()
{
	tree t;
	buildtree(t);
	putInExp(t, 1);
	return 0;
}