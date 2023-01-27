/*
    在二叉树中查找值为 x 的结点，试编写算法打印值为 x 的结点的所有祖先，假设值为 x 的结点不多于一个。
    分析：
        采用后序遍历（非递归），在遇到x之前把它的祖先结点全部入栈，当找到x时，再依次取出栈中元素。
*/
#include <iostream>
using namespace std;
// 树结点结构体
typedef struct treenode
{
    // 结点的值
    char data;
    // 结点的左右孩子指针
    struct treenode *lchild, *rchild;
} treenode, *tree;
// 结点栈的结构体
typedef struct
{
    // 树的结点
    treenode *t;
    // 此结点的左右孩子访问变量：tag = 0，左孩子已经访问过；tag = 1，右孩子已经访问过
    int tag;
} Stack;

// 建树，赋值结点
void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        // 分配空间
        t = (treenode *)malloc(sizeof(treenode));
        // 给结点赋值
        t->data = ch;
        // 左右孩子先置空
        t->lchild = NULL;
        t->rchild = NULL;
        // 递归去赋值该结点的左右结点
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// 非递归后序遍历
void findAllAncestor(tree t, char x)
{
    // 栈的堆顶指针top初始化指向0
    Stack s[10];
    int top = 0;
    while (t || top > 0)
    {
        // 从根结点开始向左延伸压入栈中并且结点的值不为x
        while (t && t->data != x)
        {
            s[++top].t = t;
            s[top].tag = 0;
            t = t->lchild;
        }
        // 如果找到了值为x的结点，将栈中的结点值输出
        if (t && t->data == x)
        {
            printf("所有的祖先结点为：\n");
            for (int i = 1; i <= top; i++)
                printf("%c ", s[i].t->data);
            return;
        }
        // 判断当前栈顶的结点的tag值为1的话，依次退栈
        while (top != 0 && s[top].tag == 1)
            top--;
        // 当前栈顶不为0，将栈顶的tag值赋为1，结点指向该结点的右孩子
        if (top != 0)
        {
            s[top].tag = 1;
            t = s[top].t->rchild;
        }
    }
}

// 主函数，测试
int main()
{
    tree t;
    buildtree(t);
    findAllAncestor(t, 'G');
    return 0;
}