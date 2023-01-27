/*
    已知二叉树以二叉链表存储，编写算法完成：对于树中每个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。
    分析：
        因为要删除以寻找到的元素为根的子树，所以删除时应采用递归后序遍历进行删除释放，寻找 x 采用先序遍历。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
    // 结点值
    char data;
    // 结点的左右孩子指针
    struct treenode *lchild, *rchild;
} treenode, *tree;

// 建树，赋值结点
void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        // 分配内存空间给结点
        t = (treenode *)malloc(sizeof(treenode));
        // 给结点赋值
        t->data = ch;
        // 将左右孩子结点置为空
        t->lchild = NULL;
        t->rchild = NULL;
        // 递归去赋值结点的左右孩子
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// 递归释放结点
void Release(tree &t)
{
    if (!t)
        return;
    Release(t->lchild);
    Release(t->rchild);
    free(t);
}

// 前序遍历
void delXSub(tree &T, char x) // 释放结点函数
{
    if (!T)
        return;
    if (T->data == x)
    {
        // 递归释放结点
        Release(T);
        // 手动去设置结点为NULL，物理结点的一个释放
        T = NULL;
    }
    if (T)
    {
        delXSub(T->lchild, x);
        delXSub(T->rchild, x);
    }
}

// 打印
void disp(tree t)
{
    if (t)
    {
        cout << t->data << " ";
        disp(t->lchild);
        disp(t->rchild);
    }
}

// 主函数，测试
int main()
{
    tree t;
    buildtree(t); // 创建一棵二叉树
    delXSub(t, 'A');
    disp(t);
    return 0;
}