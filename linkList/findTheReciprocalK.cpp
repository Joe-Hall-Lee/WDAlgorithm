/*
	��һ����ͷ���ĵ��������һ�������ҵ�ָ���ĵ����� k ����㣬������ֵ�������� 1�����򷵻� 0��ǰ���ǲ��ܸı����������ܸ�Ч��
	������
		���������һ�Σ���������ָ�룬�ʼ��ָ���׽�㣬Ȼ���� q ���ƶ� k ����㣬֮�� p��q ͬ���ƶ����� q Ϊ NULL ʱ��p ���ڵ�λ�ñ��ǵ����� k������λ�á�
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[5] = {5, 4, 3, 10, 1};
int n = 5;

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

int findTheReciprocalK(linklist &L, int k)
{
	lnode *p = L->next, *q = L->next;
	int num = 0;
	while (p)
	{
		if (num < k)
			num++;
		else
			q = q->next;
		p = p->next;
	}
	if (num < k)
		return 0;
	else
	{
		cout << "������k������ֵΪ��" << q->data << endl;
		return 1;
	}
}

int main()
{
	linklist L;
	buildlist(L);
	cout << findTheReciprocalK(L, 6) << endl;
	;
	return 0;
}