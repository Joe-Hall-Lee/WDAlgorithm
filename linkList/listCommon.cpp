/*
	已知两个链表 A、B 分别表示两个集合，其元素递增排列，编制函数，求 A 与 B 的交集，并存放于 A 链表中。
	分析：
		因为链表本身递增排序，可以设置两个指针，同时遍历 A、B 链表，同则保留，异则删除。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[4] = {1, 2, 3, 4};
int b[6] = {2, 4, 5, 6, 7, 8};
int n1 = 4, n2 = 6;

void buildlist(linklist &L, int aa[], int n)
{
	L = (linklist)malloc(sizeof(lnode));
	lnode *s, *r = L;
	for (int i = 0; i < n; i++)
	{
		s = (lnode *)malloc(sizeof(lnode));
		s->data = aa[i];
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

void listCommon(linklist &L1, linklist &L2)
{
	lnode *p1 = L1->next, *p2 = L2->next, *r = L1, *q;
	while (p1 && p2)
	{
		if (p1->data < p2->data)
		{
			q = p1;
			p1 = p1->next;
			free(q);
		}
		else if (p1->data > p2->data)
		{
			q = p2;
			p2 = p2->next;
			free(q);
		}
		else
		{
			r->next = p1;
			r = p1;
			p1 = p1->next;
			q = p2;
			p2 = p2->next;
			free(q);
		}
	}
	while (p1)
	{
		q = p1;
		p1 = p1->next;
		free(q);
	}
	while (p2)
	{
		q = p2;
		p2 = p2->next;
		free(q);
	}
	r->next = NULL;
}

int main()
{
	linklist L1, L2;
	buildlist(L1, a, n1);
	buildlist(L2, b, n2);
	cout << "L1" << endl;
	disp(L1);
	cout << "L2" << endl;
	disp(L2);
	listCommon(L1, L2);
	cout << "L1" << endl;
	disp(L1);
	return 0;
}