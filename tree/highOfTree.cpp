/*
	�Ժ����ֵ�����Ϊ�洢�ṹ������Ƶݹ��㷨�����ĸ߶ȡ�
	������
		���ֻ�и���㣬��ô�߶�Ϊ1����������ӣ���ô�߶������ӵ���������������������ȡ����ߡ�
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct treenode
{
	// ���ֵ
	char data;
	// ���������ֵ���ָ��
	struct treenode *child, *rbro;
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
		// ����ռ�
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ
		t->data = ch;
		// ��ʼ��
		t->child = NULL;
		t->rbro = NULL;
		// �ݹ鸳ֵ
		buildtree(t->child);
		buildtree(t->rbro);
	}
}

// �ݹ�������
int highOfTree(tree t)
{
	if (!t) // �ݹ�ĳ���
		return 0;
	else
	{
		// �ݹ�������������߶�
		int l = highOfTree(t->child); // ��¼�������߶�
		// �ݹ�������ֵ������߶�
		int r = highOfTree(t->rbro); // ��¼���ֵܵĸ߶ȣ�ע������high�����ټ�һ����Ϊ�������ֵܣ�ƽ��
		return max(l + 1, r);
	}
}

// ����������
int main()
{
	tree t;
	buildtree(t);
	cout << highOfTree(t) << endl;
	return 0;
}