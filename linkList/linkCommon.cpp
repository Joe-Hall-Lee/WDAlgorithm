/*
	设 A、B 是两个单链表（带头结点），其中元素递增有序，设计一个算法从 A、B 中的公共元素产生单链表C，要求不破坏 A、B 结点。
	分析：
		要求不破坏 A、B 结点，故需要重新创建分配结点空间，来进行链接。因为这两个链表是递增有序的，那么可以设置两个指针同步比较，
		相同则加入 C，不同小的那个往后移，直至链表末尾，这样的时间复杂度为 O(n)。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[4] = {2, 3, 4, 9};
int n1 = 4;
int b[5] = {4, 7, 9, 10, 11};
int n2 = 5;

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

linklist L3;

void linkCommon(linklist L1, linklist L2)
{
	L3 = (linklist)malloc(sizeof(lnode));
	lnode *p1 = L1->next, *p2 = L2->next, *s, *r;
	r = L3;
	while (p1 && p2)
	{
		if (p1->data < p2->data)
			p1 = p1->next;
		else if (p1->data > p2->data)
			p2 = p2->next;
		else
		{
			s = (lnode *)malloc(sizeof(lnode));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	r->next = NULL;
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
	linkCommon(L1, L2);
	cout << "L3:" << endl;
	disp(L3);
	return 0;
}