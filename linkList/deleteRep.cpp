/*
	在一个递增有序的线性表中，有数值相同的元素存在，若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素。
	分析：
		这道题给的是递增有序的序列，可以进行一一比较，后一个元素与当前元素相同时便删除当前元素。
*/

#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[10] = {1, 2, 3, 5, 6, 6, 7, 7, 9, 10};
int n = 10;

void buildlist(linklist &L)
{
	L = (linklist)malloc(sizeof(lnode));
	lnode *s, *r = L;
	for (int i = 0; i < n; i++)
	{
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(linklist L)
{
	lnode *s = L->next;
	while (s)

	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void deleteRep(linklist &L)
{
	if (!L->next)
		return;
	lnode *p = L->next, *q;
	while (p->next)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

int main()
{
	linklist L;
	buildlist(L);
	cout << "删除之前" << endl;
	disp(L);
	deleteRep(L);
	cout << "删除之后" << endl;
	disp(L);
	return 0;
}