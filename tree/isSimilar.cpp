/*
	������ж����ö������Ƿ����Ƶ��㷨����ν������ T1 �� T2 ���ƣ�ָ���� T1 �� T2 ���ǿյĶ�������ֻ��һ������㣻
	�� T1 ���������� T2 �������������Ƶģ��� T1 ���������� T2 �������������Ƶġ�
	������
		��ȡ�ݹ�������
*/
#include <iostream>
using namespace std;
// �����ṹ��
typedef struct treenode
{
	// ����ֵ
	char data;
	// ���Һ���ָ��
	struct treenode *lchild, *rchild;
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
		// ��ֵ
		t->data = ch;
		// ���Һ����ÿ�
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ��������
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// �ݹ�Ƚ������������� + �� = 0���� + �ǿ� = 0
int isSimilar(tree t1, tree t2)
{
	int left, right;
	if (!t1 && !t2) // t1��t2���ǿյĶ�����
		return 1;
	else if (!t1 || !t2) // t1��t2ֻ��һ��Ϊ�գ�������
		return 0;
	else
	{
		left = isSimilar(t1->lchild, t2->lchild);
		right = isSimilar(t1->rchild, t2->rchild);
		return left && right; // �������������ƣ�������
	}
}

// ������������
int main()
{
	tree t1, t2;
	buildtree(t1);
	buildtree(t2);
	cout << isSimilar(t1, t2) << endl;
	return 0;
}