/*
    假设二叉树采取二叉链表存储结构存储，试设计一个算法，计算一棵给定的二叉树所有的双分支结点个数。
    分析：
        其实二叉树各类操作都十分适合递归，这里我们同样可以采取递归的做法来进行统计双分支结点的个数。
    具体做法：
        我们最开始便定义一个静态变量，递归出口即是无左右孩子。
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

int doubleNode(tree t)
{
    if (!t)
        return 0;
    else if (t->lchild && t->rchild)
        return doubleNode(t->lchild) + doubleNode(t->rchild) + 1;
    else
        return doubleNode(t->lchild) + doubleNode(t->rchild);
}

int main()
{
    tree t;
    buildtree(t); // 创建一棵二叉树
    cout << "该二叉树中双分结点有" << doubleNode(t) << "个" << endl;
    return 0;
}