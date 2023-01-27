/*
	������������ö�������洢�ṹ�����һ���㷨����ǿն������Ŀ�ȣ������н����������һ��Ľ���������
	������
		��ȡ��α�����ͳ��ÿһ��Ľ��������ҵ����������һ�㡣
*/
#include <iostream>
using namespace std;
// �����ṹ��
typedef struct treenode
{
	// ���ֵ
	char data;
	// ���Һ��ӵ�ָ��
	struct treenode *lchild, *rchild;
} treenode, *tree;
// �����еĽṹ��
typedef struct
{
	tree data[10];
	int level[10];
	int f, r;
} Qu;

// ��������ֵ���
void buildtree(tree &t)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		t = NULL;
	else
	{
		// ��������ռ�
		t = (treenode *)malloc(sizeof(treenode));
		// ��ֵ
		t->data = ch;
		// ���Һ������ÿ�
		t->lchild = NULL;
		t->rchild = NULL;
		// �ݹ�ȥ��ֵ���Һ���
		buildtree(t->lchild);
		buildtree(t->rchild);
	}
}

int getWidth(tree b)
{
	// ����
	Qu Q;
	// ���ӽ���ָ��
	tree p;
	// ������ӵĽ����
	int k;
	// ͷβָ���ʼ��
	Q.f = Q.r = -1;
	// βָ�����������������
	Q.r++;
	// ��������
	Q.data[Q.r] = b;
	// �������Ϊ1
	Q.level[Q.r] = 1;
	// ѭ���壬ͷָ��С��βָ�뼴��ִ��
	while (Q.f < Q.r)
	{
		// ͷָ����Ƴ���
		Q.f++;
		// ������ӽ��
		p = Q.data[Q.f];
		// ������ӽ��Ĳ��
		k = Q.level[Q.f];
		// ���ӽ������
		if (p->lchild)
		{
			// βָ����ƣ��������
			Q.r++;
			Q.data[Q.r] = p->lchild;
			// ������еĽ��Ĳ��Ϊ���ӽ��Ĳ��+1
			Q.level[Q.r] = k + 1;
		}
		if (p->rchild) // �Һ������
		{
			// βָ����ƣ��������
			Q.r++;
			// �Һ��ӽ������
			Q.data[Q.r] = p->rchild;
			// ������еĽ��Ĳ��Ϊ���ӽ��Ĳ��+1
			Q.level[Q.r] = k + 1;
		}
	}
	// ������ʱ�����ֵ�ĸ��£������±꣬����ÿ��ĸ���
	int maxx = 0, i = 0, n;
	// �ӵ�һ�㿪ʼ
	k = 1;
	// ѭ���������������±�С�ڶ���β��
	while (i < Q.r)
	{
		// һ��ʼÿ��Ĭ��0��
		n = 0;
		// ���±�С�ڶ��г��Ȳ��ұ������±��Ӧ�Ĳ��Ϊk��ʱ��
		while (i <= Q.r && Q.level[i] == k)
		{
			// ÿ���������
			n++;
			// �������±����
			i++;
		}
		// ��һ��Ĳ��
		k = Q.level[i];
		// �������ֵ
		if (n > maxx)
			maxx = n;
	}
	return maxx;
}

// ������������
int main()
{
	tree t;
	buildtree(t); // ����һ�ö�����
	cout << getWidth(t) << endl;
	return 0;
}