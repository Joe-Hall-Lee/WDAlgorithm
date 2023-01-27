/*
	һ�Ŷ������Զ����������ʽ�洢����дһ���㷨�ж����Ƿ���һ����ȫ��������
	������
		��α�����ö���������������ӣ������Һ��ӣ����ȱ���ӣ����к�̱��޺��ӡ�
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
	treenode *p; // ��������
	while (!isempty(s))
	{
		outs(s, p); // ȡ������Ԫ��
		if (!p->lchild)
		{
			flag = false;
			if (p->rchild)
				ans = false;
		}
		else // ������
		{
			if (flag) // ֮ǰ������ȱ���ӵĽ��
			{
				enters(s, p->lchild);
				if (p->rchild)
					enters(s, p->rchild);
				else
					flag = false;
			}
			else // ֮ǰ����ȱ���ӵĽ��
				ans = false;
		}
	}
	return ans;
}

int main()
{
	tree t;
	buildtree(t); // ����һ�ö�����
	if (isComplete(t))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}