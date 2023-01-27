/*
    �����������ȡ��������洢�ṹ�洢�������һ���㷨������һ�ø����Ķ��������е�˫��֧��������
    ������
        ��ʵ���������������ʮ���ʺϵݹ飬��������ͬ�����Բ�ȡ�ݹ������������ͳ��˫��֧���ĸ�����
    ����������
        �����ʼ�㶨��һ����̬�������ݹ���ڼ��������Һ��ӡ�
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
    buildtree(t); // ����һ�ö�����
    cout << "�ö�������˫�ֽ����" << doubleNode(t) << "��" << endl;
    return 0;
}