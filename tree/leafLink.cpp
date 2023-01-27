/*
	���һ���㷨����������Ҷ��㰴�����ҵ�˳������һ����������ͷָ��Ϊ head������������������ʽ�洢������ʱ��Ҷ����
	��ָ������ŵ�����ָ�롣
	������
		Ҫ��Ҷ���������������Ҫ���������ҵ�˳���ҳ�Ҷ��㣬Ҫ���������ĳ���˳�򣬿��Բ����������򡢺���
		����������������
*/
#include <iostream>
using namespace std;
// �����ṹ��
typedef struct treenode
{
	// ���ֵ
	char data;
	// ���Һ���ָ��
	struct treenode *lchild, *rchild;
} treenode, *tree;

// ��������ֵ���
void buildtree(tree &t)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		// ���ڴ��������
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ
		t->data = ch;
		// ���Һ����ÿ�
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ�ȥ��ֵ
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

// ȫ��ͷ��㡢ǰ���ڵ㣬������Ȼ�������Ľṹ�壬ͨ��rchild��������
tree head = (treenode *)malloc(sizeof(treenode)), pre = NULL;

// �������
tree leafLink(tree t) // ��������t�е�����Ҷ�ӽ��������
{
	// �ݹ���������㲻Ϊ��
	if (t)
	{
		// �������������Ϊ������һֱ�ݹ���������
		leafLink(t->lchild); // �������������
		// �ҵ�Ҷ�ӽ��
		if (!t->lchild && !t->rchild) // Ҷ���
		{
			// ����ǵ�һ��
			if (!pre)
			{
				// ͷ��㸳ֵ
				head = t;
				// ����ǰ����㣬ǰ�����Ϊ��ǰ��һ����㣬��֤�����ٴ�����Ҷ�ӽ���ʱ��֪��ǰ�������˭�����ܹ���������
				pre = t;
			}
			// �����ǵ�һ��
			else
			{
				// �ͽ�ǰ��������ָ��ָ��ǰ�Ľ��
				pre->rchild = t;
				// ����ǰ����㣬��֤�����ٴ�����Ҷ�ӽ���ʱ��֪��ǰ�������˭�����ܹ���������
				pre = t;
			}
		}
		// �������ݹ�����ˣ����ҵݹ�������
		leafLink(t->rchild); // �������������
		// �������ݹ���ɺ���Խ����һ�����Ҳ���Ǹ��º��ǰ���ڵ����ָ��ָ���
		pre->rchild = NULL; // ��������β
	}
	// ��󷵻�ͷ��㼴�ɣ�����ͨ��ͷ������������������
	return head;
}

// ������������
int main()
{
	tree t;
	buildtree(t); // ����һ�ö�����
	leafLink(t);
	while (head)
	{
		cout << head->data << " ";
		head = head->rchild;
	}
	return 0;
}