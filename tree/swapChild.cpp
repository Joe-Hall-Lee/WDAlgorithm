/*
    试编写一个算法将一颗二叉树的所有结点的左右子树进行交换。
    分析：
        采用递归的方式进行交换。
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

void swapChild(tree &t) // 本质就是从叶子结点开始进行交换，一路推进到根姐点
{
    treenode *p;
    if (!t)
        return;
    if (!t->lchild && !t->rchild) // 如果没有左右孩子，就不需要交换了，直接返回
        return;
    else
    {
        swapChild(t->lchild); // 交换左子树
        swapChild(t->rchild); // 交换右子树
        p = t->lchild;
        t->lchild = t->rchild;
        t->rchild = p;
    }
}

void disp(tree t)
{
    if (t)
    {
        cout << t->data << " ";
        disp(t->lchild);
        disp(t->rchild);
    }
}

int main()
{
    tree t;
    buildtree(t); // 创建一棵二叉树
    cout << "交换过后的二叉树为（前序序列）" << endl;
    swapChild(t);
    disp(t);
    return 0;
}