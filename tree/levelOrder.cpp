/*
    试给出二叉树的自下而上、从左到右的层次遍历算法。
    分析：
        只需要在层次遍历的基础上加入栈的使用，将每次出队后的数据入栈，队列空了时，再去依次访问栈中元素，即可达到要求。
*/
#include <iostream>
using namespace std;
#define Max 10
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (treenode *)malloc(sizeof(treenode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

typedef struct stack1
{
    struct treenode *data[Max];
    int top;
} stack1;

bool isempty(stack1 s)
{
    if (s.top == -1)
        return true;
    return false;
}

bool isfull(stack1 s)
{
    if (s.top == Max - 1)
        return true;
    return false;
}

bool enters(stack1 &s, treenode *p)
{
    if (isfull(s))
    {
        cout << "栈满" << endl;
        return false;
    }
    s.data[++s.top] = p;
    return true;
}

bool outs(stack1 &s, treenode *&p)
{
    if (isempty(s))
    {
        cout << "栈空" << endl;
        return false;
    }
    p = s.data[s.top--];
    return true;
}

struct squeue1
{
    struct treenode *data[Max];
    int f, r, tag;
};

bool entersqueue(squeue1 &s, treenode *x)
{
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满" << endl;
        return false;
    }
    s.data[s.r] = x;
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}

int outsqueue(squeue1 &s, treenode *&x)
{
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空" << endl;
        return 0;
    }
    x = s.data[s.f];
    s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}

void levelOrder(tree t)
{
    stack1 s;
    squeue1 q;
    treenode *p;
    if (t)
    {
        s.top = -1;
        q.f = q.r = q.tag = 0;
        entersqueue(q, t);
        while (!((q.f == q.r) && q.tag == 0))
        {
            outsqueue(q, p);
            enters(s, p);
            if (p->lchild)
                entersqueue(q, p->lchild);
            if (p->rchild)
                entersqueue(q, p->rchild);
        }
        while (!isempty(s))
        {
            outs(s, p);
            cout << p->data << " ";
        }
    }
}

int main()
{
    tree t;
    buildtree(t); // 创建一棵二叉树
    levelOrder(t);
    return 0;
}