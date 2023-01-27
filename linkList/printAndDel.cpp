/*
    设有一个带头结点的循环单链表，其结点值均为正值。设计一个算法，反复找出循环单链表中最小值输出并删除，直到单链表空为止，再删除表头结点。
    分析：
        遍历它，为了保证不断链，设置 p、r、min、mp 4 个指针。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
    int data;
    struct lnode *next;
} lnode, *linklist;
int a[5] = {3, 5, 2, 7, 1};
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
    r->next = L;
}

void disp(linklist L)
{
    lnode *s = L->next;
    while (s != L)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

void printAndDel(linklist &L)
{
    lnode *p, *r, *min, *mp;
    while (L->next != L)
    {
        p = L->next, r = L, min = p, mp = r;
        while (p != L)
        {
            if (p->data < min->data)
            {
                min = p;
                mp = r;
            }
            else
            {
                r = p;
                p = p->next;
            }
        }
        cout << min->data << " ";
        mp->next = min->next;
        free(min);
    }
    free(L);
}

int main()
{
    linklist L;
    buildlist(L);
    cout << "L:" << endl;
    disp(L);
    printAndDel(L);
    return 0;
}