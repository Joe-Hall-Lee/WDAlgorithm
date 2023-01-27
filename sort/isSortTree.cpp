/*
    编写一个算法判断给定的二叉树是否是二叉排序树。
    分析：
        二叉排序树的中序序列是升序序列。
*/
#include <iostream>
using namespace std;

// 树结点的存储结构
typedef struct treenode
{
    // 结点的值
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
        // 分配内存
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

// 中序遍历二叉树是否是二叉排序树
// 初始化前驱值
int pre = -35555;

int isSortTree(tree t)
{
    // 先判断树是否为空
    if (!t)
        return 1;
    else
    {
        // 递归求左子树是否是二叉排序树
        int b1 = isSortTree(t->lchild);
        // 判断左孩子的值和当前结点与前驱结点值的比较
        if (b1 == 0 || ((t->data) - '0' <= pre))
            return 0;
        // 将当前结点作为下一个前驱结点保存下来
        pre = (t->data) - '0';
        // 递归求右子树的值
        return isSortTree(t->rchild);
        // 返回
    }
}

// 测试
int main()
{
    tree t;
    buildtree(t);
    cout << isSortTree(t) << endl;
    return 0;
}