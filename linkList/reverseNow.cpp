/*
	就地逆置链表。
	分析：
		采用头插法进行逆置。
*/

#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[4] = {1, 2, 3, 4};
int n = 4;

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

void reverseNow(linklist &L)
{
	lnode *p = L->next, *r;
	L->next = NULL;
	while (p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
}

int main()
{
	linklist L;
	buildlist(L);
	cout << "逆置之前" << endl;
	disp(L);
	cout << "逆置之后" << endl;
	reverseNow(L);
	disp(L);
	return 0;
}