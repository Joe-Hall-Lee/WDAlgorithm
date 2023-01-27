/*
	将一个带头结点单链表 A 分解成两个带头结点的单链表 A 和 B，使得A中含有原表中序号为奇数的元素，B 中含有原表中序号为偶数的元素，且保持其相对位置不变。
	分析：
		首先需要分配一个结点空间作为 B 的头结点，然后设置一个计数器 i，为奇数时链给 A，为偶数时链给 B。
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
	L1->next = NULL; // 原链表头结点置空
	int i = 0;
	while (p) // 要使其顺序不变，采用尾插法
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
	r1->next = NULL; // 要记得将末尾结点的指针指向NULL，不然就仍然是之前的指针，导致结果不正确
	r2->next = NULL;
}

int main()
{
	linklist L1;
	buildlist(L1);
	cout << "之前" << endl;
	disp(L1);
	divideOddAndEven(L1);
	cout << "之后" << endl;
	cout << "L1:" << endl;
	disp(L1);
	cout << "L2:" << endl;
	disp(L2);
	return 0;
}