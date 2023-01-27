/*
	设线性表 L = (a1, a2, a3, ..., an-2, an-1, an)，采用带头结点的单链表保存，设计一个空间复杂度为 O(1) 的
	算法，得到 L' = (a1, an ,a2, an-1, a3, an-2, ...)。
	分析：
		设置两个指针 slow 和 fast，其中 fast 每次走两步，slow 每次走一步，当 fast 到达链尾时，slow 刚好处于链表中间结点，接下来把 slow 后面的结点逆置，
		链表就变成了 (a1, a2, a3, ..., an, an-1, an-2, ...)，然后从中间开始遍历，依次将结点插入到前面结点后面，即可完成要求。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int n = 8;

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

void crossTheLink(linklist &L)
{
	lnode *p, *q, *l, *r;
	p = L, q = L;
	while (q->next) // 寻找中间结点
	{
		p = p->next;
		q = q->next;
		if (q->next)
			q = q->next;
	}
	q = p->next;
	p->next = NULL;
	while (q) // 逆转 p 后面的结点
	{
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	l = L->next;
	q = p->next;
	p->next = NULL;
	while (q) // 逐个进行插入
	{
		r = q->next;
		q->next = l->next;
		l->next = q;
		l = q->next;
		q = r;
	}
}

int main()
{
	linklist L;
	buildlist(L);
	disp(L);
	crossTheLink(L);
	disp(L);
	return 0;
}