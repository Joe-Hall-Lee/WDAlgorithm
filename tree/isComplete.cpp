/*
	一颗二叉树以二叉链表的形式存储，编写一个算法判断其是否是一个完全二叉树。
	分析：
		层次遍历这棵二叉树：结点无左孩子，必无右孩子；结点缺孩子，所有后继必无孩子。
*/
#include <iostream>
using namespace std;
#define Max 15
typedef struct treenode
{
	char data;
	struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree &t)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = NULL;
		t->rchild = NULL;
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

struct squeue
{
	struct treenode *data[Max];
	int f, r, tag;
};

bool isempty(squeue s)
{
	if (s.f == s.r && s.tag == 0)
		return true;
	return false;
}

bool isfull(squeue s)
{
	if (s.f == s.r && s.tag == 1)
		return true;
	return false;
}

bool enters(squeue &s, treenode *p)
{
	if (isfull(s))
		return false;
	s.data[s.r] = p;
	s.r = (s.r + 1) % Max;
	s.tag = 1;
	return false;
}

bool outs(squeue &s, treenode *&p)
{
	if (s.f == s.r && s.tag == 0)
		return false;
	p = s.data[s.f];
	s.f = (s.f + 1) % Max;
	s.tag = 0;
	return false;
}

bool isComplete(tree t)
{
	squeue s;
	s.f = s.r = s.tag = 0;
	bool flag = true, ans = true;
	if (!t->lchild && !t->rchild)
		ans = true;
	enters(s, t);
	treenode *p; // 根结点入队
	while (!isempty(s))
	{
		outs(s, p); // 取出队首元素
		if (!p->lchild)
		{
			flag = false;
			if (p->rchild)
				ans = false;
		}
		else // 有左孩子
		{
			if (flag) // 之前不存在缺孩子的结点
			{
				enters(s, p->lchild);
				if (p->rchild)
					enters(s, p->rchild);
				else
					flag = false;
			}
			else // 之前存在缺孩子的结点
				ans = false;
		}
	}
	return ans;
}

int main()
{
	tree t;
	buildtree(t); // 创建一棵二叉树
	if (isComplete(t))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}