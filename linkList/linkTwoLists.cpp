/*
	������ѭ������������ͷָ��ֱ�Ϊ h1 ��h2����дһ������������ h2 ���ӵ� h1 ֮��Ҫ�����Ӻ�������Ա���ѭ��������ʽ��
	������
		����Ҫ�ҵ� h1 ��β��㣬�ҵ�β����β���� next ָ�� h2 ���׽�㣬Ȼ���ҵ� h2 ��β��㣬���� next ָ��ָ�� h1��
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
	while (p->next != L1) // ����Ҫȥ�ж�p->next�Ƿ����L1�������жϳ��Ƿ񵽴�β���
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