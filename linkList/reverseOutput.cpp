/*
	��һ��ͷ�����������һ�㷨��β��ͷ�����ÿ������ֵ��
	������
		���������е���ջ�����ʣ������õݹ����������ڱ���βԪ�ء�
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
	lnode *r = L, *s;
	for (int i = 0; i < n; i++)
	{
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void reverseOutput(lnode *p)
{
	if (!p)
		return;
	else
	{
		reverseOutput(p->next);
		cout << p->data << " ";
	}
}

int main()
{
	lnode list;
	lnode *L = &list;
	buildlist(L);
	reverseOutput(L->next);
	return 0;
}