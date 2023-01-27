/*
	�������Ĵ�Ȩ·�����ȣ�WPL���Ƕ�����������Ҷ���Ĵ�Ȩ·������֮�͡�����һ�ö�����T�����ö�������洢�����ṹΪ
	{left, weight, right}�����������T��WPL���㷨��
	������
		���Ȩ·�����ȣ�����Ҫ֪��Ҷ����Ȩֵ��Ҳ��Ҫ֪���侭����·������������һ������ deep ������ȣ�Ҳ����
		·�����ȣ�����һ����̬���� ans �ۼӴ�Ȩ·������ʹ�õ��ݹ顣
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct treenode
{
	// ����ֵ
	char weight;
	// ���Һ���ָ��
	struct treenode *lchild, *rchild;
} treenode, *tree;

// ����
void buildtree(tree &t) // ����һ�ö�����
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
		t->weight = ch;
		// ��ʼ��
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ鸳ֵ
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ����WPL
int countWPL(tree t, int deep)
{
	// ��̬�������洢���ֵ���ں���ĩβ����
	static int ans = 0; // ���þ�̬����
	// ����Ҷ�ӽ�㣬�ۼ�ֵ
	if (!t->lchild && !t->rchild)
		ans += (deep * (t->weight - '0')); // �����Ȩ·��
	// ����������Ϊ�գ��ݹ������������Ҷ�ӽ��ͬʱ���� + 1
	if (t->lchild)
		countWPL(t->lchild, deep + 1); // ������
	// ����������Ϊ�գ��ݹ������������Ҷ�ӽ��ͬʱ���� + 1
	if (t->rchild)
		countWPL(t->rchild, deep + 1); // ������
	return ans;
}

// ����������
int main()
{
	tree t;
	buildtree(t);
	cout << countWPL(t, 0) << endl;
	return 0;
}