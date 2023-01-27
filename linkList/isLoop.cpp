/*
	设计一个算法判断一个链表是否有环。
	分析：
		通过快慢指针来处理，p 指针一次移动两个结点，q 指针一次移动一个结点，
		如果它们再次相遇了，说明链表有环，如果 p 指针为 NULL 了，说明无环。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	int data;
	struct lnode *next;
} lnode;
int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9};
int n = 15;

void buildlist(lnode *L)
{
	lnode *s, *r = L;
	r->data = a[0];
	for (int i = 1; i < n; i++)
	{
		s = (lnode *)malloc(sizeof(lnode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void disp(lnode *L)
{
	lnode *s = L;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}

lnode *isLoop(lnode *L)
{
	lnode *f = L, *s = L;
	while (s && f->next)
	{
		s = s->next;
		f = f->next->next;
		if (s->data == f->data) // 再次相遇，说明有环
			break;
	}
	if (!s || !f->next)
		return NULL;
	lnode *p = L, *q = s;
	while (p->data != q->data)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}

int main()
{
	lnode list;
	lnode *L = &list;
	buildlist(L);
	cout << "L:" << endl;
	disp(L);
	lnode *ans = isLoop(L);
	cout << "环口值为：" << ans->data << endl;
	return 0;
}