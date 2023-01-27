/*
    设计一个算法，求出指定结点在给定二叉排序树中的层次。
    分析：
        根据二叉排序树的性质，从根结点一直向下查找，每查找一次，层次便加一。
*/
#include <iostream>
using namespace std;
// 树结点的存储结构
typedef struct treenode
{
    // 结点值
    char data;
    // 左右孩子指针
    struct treenode *lchild, *rchild;
} treenode, *tree;

// 建树
void buildtree(tree &t)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        t = NULL;
    else
    {
        // 分配空间
        t = (treenode *)malloc(sizeof(treenode));
        // 赋值
        t->data = ch;
        // 初始化
        t->lchild = NULL;
        t->rchild = NULL;
        // 递归去赋值左右子树的结点
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// 找层次
int levelInSortTree(tree t, treenode *p)
{
    // 层数初始化
    int n = 0;
    // 遍历树的结点
    treenode *tt = t;
    // 根不空的话，根结点层数 + 1
    if (t)
    {
        n++;
        // 循环条件是当前结点的值不为要找的那个值
        while (tt->data != p->data)
        {
            if (tt->data > p->data) // 当前结点大了，结点指向左孩子
                tt = tt->lchild;
            else
            {
                tt = tt->rchild; // 当前结点小了，结点指向右孩子
            }
            n++;
        }
    }
    // 最后返回层数
    return n;
}

int main()
{
    tree t;
    buildtree(t);
    cout << levelInSortTree(t, t->lchild->lchild->lchild->rchild) << endl;
    return 0;
}