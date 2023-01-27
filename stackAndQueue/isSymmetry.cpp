/*
    设单链表的表头指针为 h，结点结构由 data 和 next 两个域构成，其中 data 域为字符型。
    试设计算法判断该链表的全部 n 个字符是否是中心对称，例如，xyx、xyyx 都是中心对称。
    分析：
        可以利用栈的先进后出的特性来搞定这道题，设置两个快慢指针，fast 和 slow，
        用以找到中间结点，之后将 slow 结点之后的结点依次入栈，fast指针重新指向首结点，
        然后fast和栈内元素一一比较，若存在不同，则不对称。
*/
#include <iostream>
using namespace std;
typedef struct lnode
{
    char data;
    struct lnode *next;
} lnode, *linklist;
char s1[4] = {'a', 'b', 'b', 'c'};
int n = 4;

void buildlist(linklist &L)
{
    L = (linklist)malloc(sizeof(lnode));
    lnode *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        s = (lnode *)malloc(sizeof(lnode));
        s->data = s1[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

bool isSymmetry(linklist L, int n)
{
    char *str = new char[n / 2];
    lnode *p = L->next;
    int i;
    for (i = 0; i < n / 2; i++)
    {
        str[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 != 0)
        p = p->next;
    while (p && p->data == str[i])
    {
        i--;
        p = p->next;
    }
    delete[] str;
    if (i == -1)
        return true;
    else
        return false;
}

int main()
{
    linklist L;
    buildlist(L);
    if (isSymmetry(L, n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}