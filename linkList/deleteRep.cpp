/*
	��һ��������������Ա��У�����ֵ��ͬ��Ԫ�ش��ڣ����洢��ʽΪ����������㷨ȥ����ֵ��ͬ��Ԫ�أ�ʹ���в������ظ���Ԫ�ء�
	������
		���������ǵ�����������У����Խ���һһ�Ƚϣ���һ��Ԫ���뵱ǰԪ����ͬʱ��ɾ����ǰԪ�ء�
*/

#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[10] = {1, 2, 3, 5, 6, 6, 7, 7, 9, 10};
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

void deleteRep(linklist &L)
{
	if (!L->next)
		return;
	lnode *p = L->next, *q;
	while (p->next)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

int main()
{
	linklist L;
	buildlist(L);
	cout << "ɾ��֮ǰ" << endl;
	disp(L);
	deleteRep(L);
	cout << "ɾ��֮��" << endl;
	disp(L);
	return 0;
}