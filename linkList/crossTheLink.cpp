/*
	�����Ա� L = (a1, a2, a3, ..., an-2, an-1, an)�����ô�ͷ���ĵ������棬���һ���ռ临�Ӷ�Ϊ O(1) ��
	�㷨���õ� L' = (a1, an ,a2, an-1, a3, an-2, ...)��
	������
		��������ָ�� slow �� fast������ fast ÿ����������slow ÿ����һ������ fast ������βʱ��slow �պô��������м��㣬�������� slow ����Ľ�����ã�
		����ͱ���� (a1, a2, a3, ..., an, an-1, an-2, ...)��Ȼ����м俪ʼ���������ν������뵽ǰ������棬�������Ҫ��
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
	while (q->next) // Ѱ���м���
	{
		p = p->next;
		q = q->next;
		if (q->next)
			q = q->next;
	}
	q = p->next;
	p->next = NULL;
	while (q) // ��ת p ����Ľ��
	{
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	l = L->next;
	q = p->next;
	p->next = NULL;
	while (q) // ������в���
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