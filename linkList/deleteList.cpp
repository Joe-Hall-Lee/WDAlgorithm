/*
    ��һ����ͷ���ĵ���������Ԫ�ص�����ֵ�����Ա�д����ɾ�����������ڵĽ�㡣
    ������
        �ֱ����� pre ָ��� p ָ�룬�������������������ɾ����
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
    int data;
    struct lnode *next;
} lnode, *linklist;
int a[5] = {1, 5, 3, 4, 2};
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

void deleteList(linklist &L, int min, int max)
{
    lnode *p = L->next, *pre = L;
    while (p)
    {
        if (p->data > min && p->data < max) // ��������������ɾ��
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    deleteList(L, 1, 4);
    disp(L);
    return 0;
}