/*
	�����һ���㷨���������ı��ʽ��ת��Ϊ�ȼ۵���׺���ʽ�������
	������
		��ȡ�����������������ñ��ʽ����ô��Ҫע��ĵ��������������ӣ����и���㴦��Ҷ�ӽ��
		������Ҫ������ţ���������ڷ���������ǰ�������ţ���������������������š�
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct treenode
{
	// ���ֵ
	char data;
	// ���Һ��ӵ�ָ��
	struct treenode *lchild, *rchild;
} treenode, *tree;

// ����
void buildtree(tree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		// �����ڴ�ռ�
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ
		t->data = ch;
		// ��ʼ��
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ת������
void putInExp(tree t, int deep)
{
	if (!t)
		return;
	if (!t->lchild && !t->rchild) // ��ΪҶ��㣬ֱ�����������
		cout << t->data;
	else
	{
		if (deep > 1)
			cout << "("; // �Ǹ���㣬���������
		putInExp(t->lchild, deep + 1);
		cout << t->data;
		putInExp(t->rchild, deep + 1);
		if (deep > 1)
			cout << ")";
	}
}

// ����������
int main()
{
	tree t;
	buildtree(t);
	putInExp(t, 1);
	return 0;
}