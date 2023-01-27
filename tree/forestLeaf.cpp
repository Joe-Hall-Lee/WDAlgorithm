/*
    编程求以孩子兄弟表示法存储的森林的叶子结点数。
    分析：
        如果一个结点有左孩子，那么根据孩子兄弟表示法的规则，那它一定不是叶子结点，相反，如果没有左孩子，那么
        它一定是叶子结点，其右孩子即它的兄弟，同样应该这样去判断。
*/
#include <iostream>
using namespace std;
// 结构体
typedef struct treenode
{
    // 结点值
    char data;
    // 左孩子域、右兄弟域指针
    struct treenode *child, *rbro;
} treenode, *tree;

// 建树
void buildtree(tree &t) // 先序创建一棵二叉树
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
        t->child = NULL;
        t->rbro = NULL;
        // 递归赋值
        buildtree(t->child);
        buildtree(t->rbro);
    }
}

// 递归找叶子结点
int forestLeaf(tree t)
{
    // 空结点，返回0
    if (!t) // 空则返回0，也是递归的出口
        return 0;
    // 孩子为空即左孩子域为空，为叶子结点，结果加1还要加上右兄弟子树的叶子结点
    if (!t->child) // 没有左孩子，该结点为叶子结点
        return 1 + forestLeaf(t->rbro);
    else // 有左孩子，该结点不是叶子结点
        return forestLeaf(t->child) + forestLeaf(t->rbro);
}

// 主函数测试
int main()
{
    tree t;
    buildtree(t);
    cout << forestLeaf(t) << endl;
    return 0;
}