/*
	编写一个递归算法，在一棵有n个结点的、随机建立起来的二叉排序树上查找第k小的元素，并返回指向该结点的指针，要求算法的平均
	时间复杂度为 O(log2n)。二叉排序树的每个结点中除 data、lchild、rchild 等数据成员外，增加一个 count 成员，保存以该结点为根的
	子树的结点个数。
	分析：
		利用递归的思想，将各种情况罗列清楚。
		1．t->lchild 为空
		① 如果 t->rchild 非空且 k = 1，那么根据二叉排序树的特性，t即为第k小
		② 如果 t->rchild 非空且 k != 1，那么第k小的数肯定在右子树中
		2．如果t->lchild 非空
		① 如果 t->lchild->count == k - 1，那么 t 即为第 k 小
		② 如果 t->lchild->count > k - 1，那么第 k 小在左子树
		③ 如果 t->lchild->count < k - 1，那么第 k 小在右子树，寻找第 k - (t->lchild->count + 1)小的元素
*/

typedef struct node
{
	int data;
	int count; // 子树结点个数
	struct node *left, *right;
} Tree;
#include <stdio.h>
#include <stdlib.h>

Tree *create(Tree *T) // 先序创建一棵排序二叉树
{
	int data;
	printf("请输入当前结点值：data = ");
	scanf("%d", &data);
	getchar();
	if (data != -1)
	{
		T = (Tree *)malloc(sizeof(Tree));
		T->data = data;
		T->left = NULL;
		T->right = NULL;
		T->left = create(T->left);
		T->right = create(T->right);
	}
	return T;
}

int getCount(Tree *T) // 统计每个结点的以它为根的子树上的结点个数
{
	if (!T)
		return 0;
	int lcount, rcount;
	lcount = getCount(T->left);
	rcount = getCount(T->right);
	T->count = lcount + rcount + 1;
	return lcount + rcount + 1;
}

Tree *findKth(Tree *T, int k)
{
	if (k < 1 || k > T->count)
		return NULL;
	if (!T->left)
	{
		if (k == 1)
			return T;
		else
			return findKth(T->right, k - 1);
	}
	else
	{
		if (T->left->count == k - 1)
			return T;
		if (T->left->count > k - 1)
			return findKth(T->left, k);
		if (T->left->count < k - 1)
			return findKth(T->right, k - (T->left->count + 1));
	}
}

int main()
{
	Tree *T = (Tree *)malloc(sizeof(Tree));
	Tree *p;
	int k = 5;
	T = create(T);
	getCount(T);
	p = findKth(T, k);
	if (p)
		printf("第 %d 小的结点值为 %d", k, p->data);
	return 0;
}