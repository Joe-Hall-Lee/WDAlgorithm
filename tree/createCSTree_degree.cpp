/*
	已知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子-兄弟链表。
	分析：
		设立一个类型为树姐点的数组，将层次序列里面的所有值放到该数组中，将其所有节点的 fch 和 sub 值为空
		然后一次去遍历节点，取出度数 d，若 d > 0,说明该节点有孩子，将第一个孩子放到左指针 fch，其他孩子
		一次放到 sub 中，注意这里会有变化，代码里再详说
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
	// 节点值
	char data;
	// 左右孩子指针，左孩子右兄弟
	struct treenode *child, *rbro;
} treenode, *tree;

// 构造链表
void createCSTree_degree(tree &t, char e[], int degree[], int n)
{
	// 动态申请结点数组
	tree *point = new tree[10];
	for (int i = 0; i < n; i++)
	{
		// 给每个结点动态申请内存
		point[i] = (treenode *)malloc(sizeof(treenode));
		// 给每个结点初始化，初始化为给的字母和对应的左右指针初始化为空
		point[i]->data = e[i];
		point[i]->child = point[i]->rbro = NULL;
	}
	// 孩子结点序号
	int k = 0;
	// 按照给的结点顺序访问结点
	for (int i = 0; i < n; i++)
	{
		// 获取该结点的度
		int d = degree[i];
		// 如果有度，说明有孩子结点
		if (d)
		{
			// 孩子序号递增
			k++;
			// 将第一个孩子作为自己的左孩子结点
			point[i]->child = point[k];
			// 剩余的孩子每个结点一次为前一个结点的兄弟结点
			for (int j = 2; j <= d; j++)
			{
				// 孩子序号递增
				k++;
				// 前一个结点的右兄弟指针指向现在孩子序号的结点
				point[k - 1]->rbro = point[k];
			}
		}
	}
	t = point[0];
	// 链表的头为第一个结点
	delete[] point;
	// 动态申请的内存要进行一个释放，防止内存泄漏
}

// 输出最后孩子兄弟表示的树的先序序列进行验证
void disp(tree t)
{
	if (t)
	{
		cout << t->data << " ";
		disp(t->child);
		disp(t->rbro);
	}
}

// 主函数测试
int main()
{
	// 树
	tree t;
	// 层次遍历序列
	char e[8] = "ABCDEFG";
	// 每个结点度数数组
	int degree[8] = {3, 2, 1, 0, 0, 0, 0};
	// 构造这样的函数
	createCSTree_degree(t, e, degree, 7);
	// 输出这样的二叉树验证
	disp(t);
	return 0;
}