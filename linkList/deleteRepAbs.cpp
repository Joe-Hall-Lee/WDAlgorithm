/*
	用单链表保存 n 个整数，节点的结构为 [data][next],且 |data| <= n。现要求设计一个时间复杂度尽可能高效算法，
	对于链表中绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
	分析：
		题目中提到时间复杂度尽可能高效，其本质上就是暗示我们采用空间换时间的方式。因为数据是小于等于 n 的，可以开辟一块
		大小为 n + 1 的数组，初始值为 0，之后遍历链表，结点值即是寻找的下标，如果下标所在的数组值为 0，则将值变为 1，如果
		数组值已经为 1，则说明在此之前遇见过绝对值相同的元素，故将此结点删除。
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
	int *q = (int *)malloc(sizeof(int) * (n + 1)); // 大小是 sizeof(int) * (n + 1)
	for (int i = 0; i < n + 1; i++)				   // 赋初值0
		*(q + i) = 0;
	int s;
	while (p->next)
	{
		s = abs(p->next->data);
		if (*(q + s) == 0) // 首次访问，做上记录
		{
			*(q + s) = 1;
			p = p->next;
		}
		else
		{
			f = p->next;
			p->next = f->next; // 剔除
			free(f);		   // 释放
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
	cout << "之后" << endl;
	disp(L);
	return 0;
}