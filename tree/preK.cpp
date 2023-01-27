/*
    假设二叉树采用二叉链表存储结构存储，试设计一个算法，求先序遍历序列中第k（1 <= k <= 二叉树中结点个数）个结点的值。
    分析：
        每遍历一个结点，计数器便加一，直至等于k。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct biTree
{
    // 结点的值
    char data;
    // 结点的左右孩子指针
    struct biTree *lchild, *rchild;
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
        // 对结点进行内存分配
        t = (treenode *)malloc(sizeof(treenode));
        // 对结点进行赋值
        t->data = ch;
        // 初始化，左右孩子结点为空
        t->lchild = NULL;
        t->rchild = NULL;
        // 递归去赋值左右子树
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// 计数器
int i = 1;
// 字符
char ch;

char preK(tree t, int k)
{
    if (!t)
        return '#';
    if (i == k) // 找到后，记录下来
        return t->data;
    i++;
    ch = preK(t->lchild, k);
    if (ch != '#')
        return ch;
    ch = preK(t->rchild, k);
    return ch;
}

// 主函数，测试
int main()
{
    tree t;
    buildtree(t); // 创建一棵二叉树
    cout << preK(t, 7) << endl;
    return 0;
}