/*
    假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。
    分析：
        采用层次遍历。
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
    q[++r] = t; // 将根结点入队
    tree p;
    while (f < r)
    {
        p = q[++f]; // 取出队首元素
        if (p->lchild)
            q[++r] = p->lchild; // 将结点入队
        if (p->rchild)
            q[++r] = p->rchild; // 将结点入队
        if (f == L)             // 如果一层的元素已取完，高度+1
        {
            ans++;
            L = r;
        }
    }
    return ans;
}

int main()
{
    // 创建二叉树
    tree t;
    buildtree(t);
    cout << "树的高度为：" << highOfBiTree(t) << endl;
    return 0;
}