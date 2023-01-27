/*
    ������������ö�������洢�ṹ�����һ���ǵݹ��㷨��������ĸ߶ȡ�
    ������
        ���ò�α�����
*/
#include <iostream>
using namespace std;
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

int highOfBiTree(tree t)
{
    if (!t)
        return 0;
    tree q[10];
    int f = -1, r = -1, L = 0, ans = 0;
    q[++r] = t; // ����������
    tree p;
    while (f < r)
    {
        p = q[++f]; // ȡ������Ԫ��
        if (p->lchild)
            q[++r] = p->lchild; // ��������
        if (p->rchild)
            q[++r] = p->rchild; // ��������
        if (f == L)             // ���һ���Ԫ����ȡ�꣬�߶�+1
        {
            ans++;
            L = r;
        }
    }
    return ans;
}

int main()
{
    // ����������
    tree t;
    buildtree(t);
    cout << "���ĸ߶�Ϊ��" << highOfBiTree(t) << endl;
    return 0;
}