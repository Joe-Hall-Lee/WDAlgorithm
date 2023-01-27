/*
	�õ������� n ���������ڵ�ĽṹΪ [data][next],�� |data| <= n����Ҫ�����һ��ʱ�临�ӶȾ����ܸ�Ч�㷨��
	���������о���ֵ��ȵĽ�㣬��������һ�γ��ֵĽ���ɾ���������ֵ��ȵĽ�㡣
	������
		��Ŀ���ᵽʱ�临�ӶȾ����ܸ�Ч���䱾���Ͼ��ǰ�ʾ���ǲ��ÿռ任ʱ��ķ�ʽ����Ϊ������С�ڵ��� n �ģ����Կ���һ��
		��СΪ n + 1 �����飬��ʼֵΪ 0��֮������������ֵ����Ѱ�ҵ��±꣬����±����ڵ�����ֵΪ 0����ֵ��Ϊ 1�����
		����ֵ�Ѿ�Ϊ 1����˵���ڴ�֮ǰ����������ֵ��ͬ��Ԫ�أ��ʽ��˽��ɾ����
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[6] = {1, -4, 2, 3, 4, -2};
int n = 6;

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

void deleteRepAbs(linklist &L, int n)
{
	lnode *p = L, *f;
	int *q = (int *)malloc(sizeof(int) * (n + 1)); // ��С�� sizeof(int) * (n + 1)
	for (int i = 0; i < n + 1; i++)				   // ����ֵ0
		*(q + i) = 0;
	int s;
	while (p->next)
	{
		s = abs(p->next->data);
		if (*(q + s) == 0) // �״η��ʣ����ϼ�¼
		{
			*(q + s) = 1;
			p = p->next;
		}
		else
		{
			f = p->next;
			p->next = f->next; // �޳�
			free(f);		   // �ͷ�
		}
	}
	free(q);
}

int main()
{
	linklist L;
	buildlist(L);
	cout << "L" << endl;
	disp(L);
	deleteRepAbs(L, 4);
	cout << "֮��" << endl;
	disp(L);
	return 0;
}