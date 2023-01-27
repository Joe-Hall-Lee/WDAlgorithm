/*
	�� A��B ��������������ͷ��㣩������Ԫ�ص����������һ���㷨�� A��B �еĹ���Ԫ�ز���������C��Ҫ���ƻ� A��B ��㡣
	������
		Ҫ���ƻ� A��B ��㣬����Ҫ���´���������ռ䣬���������ӡ���Ϊ�����������ǵ�������ģ���ô������������ָ��ͬ���Ƚϣ�
		��ͬ����� C����ͬС���Ǹ������ƣ�ֱ������ĩβ��������ʱ�临�Ӷ�Ϊ O(n)��
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