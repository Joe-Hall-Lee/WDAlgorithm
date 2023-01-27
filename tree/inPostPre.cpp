/*
	д�����������������������ָ������ں����ǰ�������㷨��
	������
		�ں��������У������ p ������Ů��������Ů����ǰ������������Ů��������Ů��������Ů����ǰ��������� p ������Ů���ޣ�
		��������������ָ��ĳ���Ƚ�� f��p �� f �������а���������ĵ�һ����㣩���� f ������Ů����������Ů�ǽ�� p �ں����е�ǰ����
		��f������Ů����˳��ǰ����˫�׵�˫�ף�һֱ�ҵ�˫��������Ů����ʱ����Ů��p��ǰ����������һ��������� p ����������ĵ�
		һ����㣬���� p ������ͺ����¾�û��ǰ����
*/
#include <iostream>
using namespace std;
// �������������ṹ��
typedef struct treenode
{
	// ����ֵ
	char data;
	// ���Һ���ָ��
	struct treenode *lchild, *rchild;
	// ltag��rtag
	int ltag, rtag;
} treenode, *tree;

// ��������ֵ���
void buildtree(tree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		// �����ڴ�
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ�����
		t->data = ch;
		// ��ʼ��
		t->lchild = NULL;
		t->rchild = NULL;
		t->ltag = t->rtag = 0;
		// �ݹ鸳ֵ
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// �����������ı�����ǰ�����
tree pre;

// ����������
void zx(tree &t)
{
	// �ݹ������
	if (t)
	{
		// ��������
		zx(t->lchild);
		if (!t->lchild) // ���ӿ�
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		else
			t->ltag = 0;
		if (pre && !pre->rchild) // û���Һ���
		{
			pre->rtag = 1;	 // ǰ������к�̽��
			pre->rchild = t; // ��̽��ָ��ǰ
		}
		pre = t; // ����ǰ�����
		zx(t->rchild);
	}
}

// �Һ�̵�ǰ�����
tree inPostPre(tree t, treenode *p) // ����ǰ�����
{
	// ���ָ��
	treenode *q;
	// �ý�����Һ��ӣ���������Һ���
	if (p->rtag == 0)
		return p->rchild;
	// �ý��û���Һ��ӵ�����£������ӣ������������
	else if (p->ltag == 0)
		return p->lchild;
	// �ý���ǰ��Ϊ�գ���Ϊ�����һ����㣬�޺���ǰ��
	else if (!p->lchild)
		q = NULL;
	// ����
	else
	{
		// �����������������Ƚ��
		while (p->lchild && p->ltag == 1) // ���������û�����ӣ�������ǰ��
			p = p->lchild;
		// ���ҵ����Ƚ�㣬�������ӣ������������
		if (p->ltag == 0)
			q = p->lchild;
		// ������û�к���ǰ��
		else
			q = NULL;
	}
	return q;
}

// ������������
int main()
{
	tree t;
	buildtree(t);
	zx(t);										   // ���������������
	cout << inPostPre(t, t->rchild)->data << endl; // �ֶ�ָ��һ�����
	return 0;
}