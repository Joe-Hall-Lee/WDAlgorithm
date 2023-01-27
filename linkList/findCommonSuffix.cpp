/*
	存在这样一种情况，如果两个单词有相同的后缀，那我们可以将后缀作为公共部分存储，比如 being 和 loading，其中 ing 就可以作为
	公共部分，现在存在两个链表，含有公共部分，设计一个高效算法找到其公共后缀真实位置。
	分析：
		如果单纯地让两条链表的指针同步移动，那么只有两条链表长度相同时才可能在公共部分的起始位置相遇，
		所以应该让它们处于同一起跑线上，故而应该让较长的链表先走，具体走多少，应该是两条链表的长度之差。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
	char data;
	struct lnode *next;
} lnode, *linklist;
char a[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
char b[5] = {'b', 'e', 'i', 'n', 'g'};
int n1 = 7, n2 = 5;

void buildlist(linklist &L, char aa[], int n)
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

int length(linklist L)
{
	int ans = 0;
	lnode *s = L->next;
	while (s)
	{
		ans++;
		s = s->next;
	}
	return ans;
}

linklist findCommonSuffix(linklist L1, linklist L2)
{
	int len1 = length(L1), len2 = length(L2);
	int dist = abs(len1 - len2);
	lnode *p = L1->next, *q = L2->next;
	if (len1 >= len2)
	{
		while (dist--)
			p = p->next;
	}
	else
	{
		while (dist--)
			q = q->next;
	}
	while (p)
	{
		if (p->data != q->data)
		{
			p = p->next;
			q = q->next;
		}
		else
			return p;
	}
	return p;
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
	linklist ans = findCommonSuffix(L1, L2);
	cout << "公共后缀的起始结点为：" << ans->data << endl;
	return 0;
}