/*
	有两个循环单链表，链表头指针分别为 h1 和h2，编写一个函数将链表 h2 链接到 h1 之后，要求连接后的链表仍保持循环链表形式。
	分析：
		首先要找到 h1 的尾结点，找到尾结点后将尾结点的 next 指向 h2 的首结点，然后找到 h2 的尾结点，将其 next 指针指向 h1。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[4] = {1, 2, 3, 4};
int b[5] = {5, 6, 7, 8, 9};
int n1 = 4, n2 = 5;

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
	r->next = L;
}

void disp(linklist L)
{
	lnode *s = L->next;
	while (s != L)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

void linkTwoLists(linklist &L1, linklist &L2)
{
	lnode *p = L1->next, *q = L2->next;
	while (p->next != L1) // 这里要去判断p->next是否等于L1，进而判断出是否到达尾结点
		p = p->next;
	while (q->next != L2)
		q = q->next;
	p->next = L2->next;
	q->next = L1;
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
	linkTwoLists(L1, L2);
	cout << "L1" << endl;
	disp(L1);
	return 0;
}