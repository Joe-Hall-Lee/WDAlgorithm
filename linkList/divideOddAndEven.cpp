/*
	��һ����ͷ��㵥���� A �ֽ��������ͷ���ĵ����� A �� B��ʹ��A�к���ԭ�������Ϊ������Ԫ�أ�B �к���ԭ�������Ϊż����Ԫ�أ��ұ��������λ�ò��䡣
	������
		������Ҫ����һ�����ռ���Ϊ B ��ͷ��㣬Ȼ������һ�������� i��Ϊ����ʱ���� A��Ϊż��ʱ���� B��
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode, *linklist;
int a[5] = {2, 7, 4, 1, 9};
int n = 5;

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

void divideOddAndEven(linklist &L1)
{
	L2 = (linklist)malloc(sizeof(lnode));
	L2->next = NULL;
	lnode *r1 = L1, *r2 = L2, *p = L1->next;
	L1->next = NULL; // ԭ����ͷ����ÿ�
	int i = 0;
	while (p) // Ҫʹ��˳�򲻱䣬����β�巨
	{
		i++;
		if (i % 2 == 0)
		{
			r2->next = p;
			r2 = p;
		}
		else
		{
			r1->next = p;
			r1 = p;
		}
		p = p->next;
	}
	r1->next = NULL; // Ҫ�ǵý�ĩβ����ָ��ָ��NULL����Ȼ����Ȼ��֮ǰ��ָ�룬���½������ȷ
	r2->next = NULL;
}

int main()
{
	linklist L1;
	buildlist(L1);
	cout << "֮ǰ" << endl;
	disp(L1);
	divideOddAndEven(L1);
	cout << "֮��" << endl;
	cout << "L1:" << endl;
	disp(L1);
	cout << "L2:" << endl;
	disp(L2);
	return 0;
}