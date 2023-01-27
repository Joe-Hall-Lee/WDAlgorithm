/*
	给一个非循环双向链表增加一个 freq 值，用以表示它的访问频率，每访问一次 freq 就 + 1，然后需要将该链表按照非增的顺序
	排列，同时最近访问的结点排在相同频度结点的前面，以便使频繁访问的结点总是靠近表头。试编写符合上述要求的 Locate(L, x)
	函数，该运算为函数过程，返回找到结点的地址，类型为指针型。
	分析：
		这道题拆分开来就是查找+排序，需要先找到要访问的结点，更改它的 freq 值，然后按照 freq 值的大小寻找插入位置，
		这样便完成了一次 Locate 操作。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data, f;
	struct lnode *next, *prior;
} lnode, *linklist;
int a[5] = {1, 2, 3, 4, 5};
int n = 5;

void buildlist(linklist &L)
{
	L = (linklist)malloc(sizeof(lnode));
	lnode *r = L, *s;
	L->prior = NULL;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		s->f = 0;
		s->next = r->next;
		r->next = s;
		s->prior = r;
		r = s;
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

linklist Locate(linklist &L, int x)
{
	lnode *p = L->next, *q;
	while (p && p->data != x)
		p = p->next;
	if (!p)
		cout << "没有x这个结点" << endl;
	else // 如果找到
	{
		p->f++; // freq+1
		q = p->prior;
		if (p->next)
			p->next->prior = q; // 将该结点抠出来
		q->next = p->next;
		while (q != L && q->f <= p->f)
			q = q->prior;
		p->next = q->next;
		q->next->prior = p;
		p->prior = q;
		q->next = p;
	}
	return p;
}

int main()
{
	linklist L;
	buildlist(L);
	disp(L);
	Locate(L, 5);
	Locate(L, 5);
	Locate(L, 4);
	Locate(L, 4);
	disp(L);
	return 0;
}