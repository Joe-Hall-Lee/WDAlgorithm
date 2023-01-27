/*
	设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为 head。二叉树按二叉链表方式存储，链接时用叶结点的
	右指针来存放单链表指针。
	分析：
		要将叶结点连起来，首先要按从左至右的顺序找出叶结点，要满足这样的出场顺序，可以采用先序、中序、后序，
		这里采用中序遍历。
*/
#include <iostream>
using namespace std;
// 树结点结构体
typedef struct treenode
{
	// 结点值
	char data;
	// 左右孩子指针
	struct treenode *lchild, *rchild;
} treenode, *tree;

// 建树，赋值结点
void buildtree(tree &t)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		// 将内存分配给结点
		t = (treenode *)malloc(sizeof(treenode));
		// 赋值
		t->data = ch;
		// 左右孩子置空
		t->lchild = NULL;
		t->rchild = NULL;
		// 递归去赋值
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// 全局头结点、前驱节点，类型仍然是树结点的结构体，通过rchild链接起来
tree head = (treenode *)malloc(sizeof(treenode)), pre = NULL;

// 中序遍历
tree leafLink(tree t) // 将二叉树t中的所有叶子结点连起来
{
	// 递归条件，结点不为空
	if (t)
	{
		// 将根结点左孩子作为参数，一直递归向左延伸
		leafLink(t->lchild); // 中序遍历左子树
		// 找到叶子结点
		if (!t->lchild && !t->rchild) // 叶结点
		{
			// 如果是第一个
			if (!pre)
			{
				// 头结点赋值
				head = t;
				// 保留前驱结点，前驱结点为当前的一个结点，保证后面再次遇到叶子结点的时候知道前驱结点是谁，并能够链接起来
				pre = t;
			}
			// 若不是第一个
			else
			{
				// 就将前驱结点的右指针指向当前的结点
				pre->rchild = t;
				// 更新前驱结点，保证后面再次遇到叶子结点的时候知道前驱结点是谁，并能够链接起来
				pre = t;
			}
		}
		// 左子树递归完成了，向右递归右子树
		leafLink(t->rchild); // 中序遍历右子树
		// 右子树递归完成后可以将最后一个结点也就是更新后的前驱节点的右指针指向空
		pre->rchild = NULL; // 设置链表尾
	}
	// 最后返回头结点即可，可以通过头结点来遍历整个结点链
	return head;
}

// 主函数，测试
int main()
{
	tree t;
	buildtree(t); // 创建一棵二叉树
	leafLink(t);
	while (head)
	{
		cout << head->data << " ";
		head = head->rchild;
	}
	return 0;
}