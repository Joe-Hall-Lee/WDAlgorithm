/*
	假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表归并为一个按元素递减的单链表，
	并要求利用原来两个单链表的结点存放归并后的单链表。
	分析：
		因为链表递增，所以可以采用头插法进行处理，以 a 链为起始链，进行归并。
*/
#include <iostream>
using namespace std;

typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[4] = {1, 2, 3, 4};
int b[5] = {3, 4, 5, 6, 7};
int n1 = 4, n2 = 5;

void buildlist(linklist &L, int aa[], int n)
{
	L = (linklist)malloc(sizeof(lnode));
	lnode *r = L, *s;
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

void mergeListsInLink(linklist &L1, linklist &L2)
{
	lnode *p1 = L1->next, *p2 = L2->next, *r;
	L1->next = NULL;
	while (p1 && p2)
	{
		if (p1->data <= p2->data)
		{
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}
		else
		{
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}
	if (p1)
		p2 = p1;
	while (p2)
	{
		r = p2->next;
		p2->next = L1->next;
		L1->next = p2;
		p2 = r;
	}
	free(L2);
}

int main()
{
	linklist L1, L2;
	buildlist(L1, a, n1);
	buildlist(L2, b, n2);
	cout << "L1:" << endl;
	disp(L1);
	cout << "L2:" << endl;
	disp(L2);
	mergeListsInLink(L1, L2);
	cout << "合并之后" << endl;
	disp(L1);
	return 0;
}