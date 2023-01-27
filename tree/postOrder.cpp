// 非递归后序遍历二叉树
#include <iostream>
using namespace std;
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
    int tag;
} TreeNode, *Tree;

void createtree(Tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (TreeNode *)malloc(sizeof(TreeNode));
        t->data = ch;
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        createtree(t->lchild);
        createtree(t->rchild);
    }
}

void postOrder(Tree t) // 后序非递归遍历
{
    struct TreeNode *stack[100];
    int top = -1;
    TreeNode *p = t;
    while (p || top != -1)
    {
        if (p)
        {
            top++;
            stack[top] = p;
            p = p->lchild;
        }
        else
        {
            p = stack[top];
            if (p->rchild && p->rchild->tag == 0)
                p = p->rchild;
            else
            {
                top--;
                cout << p->data << " ";
                p->tag = 1;
                p = NULL;
            }
        }
    }
}

int main()
{
    Tree t;
    createtree(t);
    postOrder(t);
    return 0;
}