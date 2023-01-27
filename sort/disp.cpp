// 设计一个算法，从小到大输出二叉排序树中所有值不小于k的关键字。
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
        // 递归去赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// 输出 >= k 的关键字
void disp(tree t, char k)
{
    // 空树
    if (!t)
        return;
    // 右子树
    if (t->rchild)
        disp(t->rchild, k);
    // 根输出
    if (t->data >= k)
        cout << t->data << " ";
    // 左子树
    if (t->lchild)
        disp(t->lchild, k);
}

int main()
{
    tree t;
    buildtree(t);
    disp(t, 'E');
    return 0;
}