// �����֣�ͷ�巨
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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

linklist L2;

void cutList(linklist &L1)
{
	L2 = (linklist)malloc(sizeof(lnode));
	L2->next = NULL;
	lnode *p = L1->next, *q = p->next, *r = L1;
	L1->next = NULL; // ԭ����ͷ����ÿ�
	while (p)
	{
		r->next = p;
		r = p;
		p = p->next;
		if (p)
			q = p->next;
		p->next = L2->next;
		L2->next = p;
		p = q;
	}
	r->next = NULL;
}

int main()
{
	linklist L1;
	buildlist(L1);
	cout << "һ��ʼ L1" << endl;
	disp(L1);
	cutList(L1);
	cout << "֮�� L1" << endl;
	disp(L1);
	cout << "֮�� L2" << endl;
	disp(L2);
	return 0;
}