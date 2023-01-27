/*
    p �� q �ֱ�Ϊָ��ö�������������������ָ�룬�Ա�д�㷨���ҵ� p �� q ������������Ƚ��r��
    ������
        ������������ȴ�������������ջ�ֱ� p��q �����ȴ���ջ�У���Ϊջ������������Ƚ�㣬
        ���Կ�����������Ѱ����ͬ��㣬��һ���ҵ�����ͬ����������������Ƚ�㡣
*/
#include <iostream>
using namespace std;
// �����ṹ��
typedef struct treenode
{ // ���ֵ
    char data;
    // ���Һ���ָ��
    struct treenode *lchild, *rchild;
} treenode, *tree;

// ���ջ�Ľṹ��
typedef struct
{
    // ���Ľ��
    treenode *t;
    // ���Һ��ӷ��ʱ�����tag = 0�����ӷ��ʹ���tag = 1���Һ��ӷ��ʹ�
    int tag;
} Stack;

// ��������ֵ���
void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        // ��������ռ�
        t = (treenode *)malloc(sizeof(treenode));
        // �Խ�㸳ֵ
        t->data = ch;
        // ���Һ����ÿ�
        t->lchild = NULL;
        t->rchild = NULL;
        // �ݹ鸳ֵ���Һ���
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// �ǵݹ�������
tree nearestComAncestor(tree t, treenode *p, treenode *q)
{
    // ��������ջ
    Stack S1[10], S2[10];
    // ջ��ָ��ĳ�ʼ��
    int top1 = 0, top2;
    // ����������ָ��
    treenode *tt = t;
    // ��ѭ������������ǰ�����Ľ�㲻��Ϊ�ջ���ջ1��ָ��>0��ջ��Ϊ�գ�
    while (tt || top1 > 0)
    {
        // ��������ѹ��ջ
        while (tt)
        {
            S1[++top1].t = tt; // ѹ��ջ��
            S1[top1].tag = 0;  // ���ӷ��ʹ�
            tt = tt->lchild;   // ����ָ������
        }
        while (top1 != 0 && S1[top1].tag == 1) // ջ1��Ϊ�ղ���ջ������tag=1
        {
            // ���ջ���Ľ�����p���͸��Ƶ�ջ2�У�ջ2��ջ��ָ���ʱ��ֵtop1
            if (S1[top1].t == p)
            {
                for (int i = 1; i <= top1; i++)
                    S2[i] = S1[i];
                top2 = top1;
            }
            // ���ջ���Ľ�����q����ջ1����ƥ��
            if (S1[top1].t == q)
            {
                for (int i = top1; i > 0; i--)
                {
                    for (int j = top2; j > 0; j--)
                    {
                        if (S2[j].t == S1[i].t)
                            return S1[i].t;
                    }
                }
            }
            top1--; // ��ջ
        }
        // ջ����ʱ����ջ������tag = 1�����ҵ�ǰ��һ�����ָ��ý����Һ���
        if (top1 != 0)
        {
            S1[top1].tag = 1;
            tt = S1[top1].t->rchild;
        }
    }
    return NULL;
}

// ������������
int main()
{
    tree t;
    buildtree(t);
    treenode *p = t->rchild->lchild, *q = t->rchild->rchild;
    cout << nearestComAncestor(t, p, q)->data << endl;
    return 0;
}