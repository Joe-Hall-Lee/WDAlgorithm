/*
    按递增次序输出单链表各结点的数据元素，并释放结点所占的存储空间。
    分析：
        可以直接进行遍历，找到目前最小值进行输出，然后释放，注意不要断链。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
    int data;
    struct lnode *next;
} lnode, *linklist;
int a[5] = {2, 5, 3, 8, 1};
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

void outputLinkAndFree(linklist &L)
{
    while (L->next)
    {
        lnode *r = L, *p = r->next;
        while (p->next)
        {
            if (p->next->data < r->next->data)
                r = p;
            p = p->next;
        }
        cout << r->next->data << " ";
        lnode *q = r->next;
        r->next = q->next;
        free(q);
    }
    free(L);
}

int main()
{
    linklist L;
    buildlist(L);
    outputLinkAndFree(L);
    return 0;
}