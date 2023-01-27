/*
	有一个带头结点的单链表，设计一个函数找到指定的倒数第 k 个结点，输出结点值，并返回 1，否则返回 0，前提是不能改变链表，尽可能高效。
	分析：
		对链表遍历一次，设立两个指针，最开始均指向首结点，然后让 q 先移动 k 个结点，之后 p、q 同步移动，当 q 为 NULL 时，p 所在的位置便是倒数第 k个结点的位置。
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
		cout << "倒数第k个结点的值为：" << q->data << endl;
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