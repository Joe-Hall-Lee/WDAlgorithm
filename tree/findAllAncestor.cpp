/*
    �ڶ������в���ֵΪ x �Ľ�㣬�Ա�д�㷨��ӡֵΪ x �Ľ����������ȣ�����ֵΪ x �Ľ�㲻����һ����
    ������
        ���ú���������ǵݹ飩��������x֮ǰ���������Ƚ��ȫ����ջ�����ҵ�xʱ��������ȡ��ջ��Ԫ�ء�
*/
#include <iostream>
using namespace std;
// �����ṹ��
typedef struct treenode
{
    // ����ֵ
    char data;
    // �������Һ���ָ��
    struct treenode *lchild, *rchild;
} treenode, *tree;
// ���ջ�Ľṹ��
typedef struct
{
    // ���Ľ��
    treenode *t;
    // �˽������Һ��ӷ��ʱ�����tag = 0�������Ѿ����ʹ���tag = 1���Һ����Ѿ����ʹ�
    int tag;
} Stack;

// ��������ֵ���
void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        // ����ռ�
        t = (treenode *)malloc(sizeof(treenode));
        // ����㸳ֵ
        t->data = ch;
        // ���Һ������ÿ�
        t->lchild = NULL;
        t->rchild = NULL;
        // �ݹ�ȥ��ֵ�ý������ҽ��
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// �ǵݹ�������
void findAllAncestor(tree t, char x)
{
    // ջ�ĶѶ�ָ��top��ʼ��ָ��0
    Stack s[10];
    int top = 0;
    while (t || top > 0)
    {
        // �Ӹ���㿪ʼ��������ѹ��ջ�в��ҽ���ֵ��Ϊx
        while (t && t->data != x)
        {
            s[++top].t = t;
            s[top].tag = 0;
            t = t->lchild;
        }
        // ����ҵ���ֵΪx�Ľ�㣬��ջ�еĽ��ֵ���
        if (t && t->data == x)
        {
            printf("���е����Ƚ��Ϊ��\n");
            for (int i = 1; i <= top; i++)
                printf("%c ", s[i].t->data);
            return;
        }
        // �жϵ�ǰջ���Ľ���tagֵΪ1�Ļ���������ջ
        while (top != 0 && s[top].tag == 1)
            top--;
        // ��ǰջ����Ϊ0����ջ����tagֵ��Ϊ1�����ָ��ý����Һ���
        if (top != 0)
        {
            s[top].tag = 1;
            t = s[top].t->rchild;
        }
    }
}

// ������������
int main()
{
    tree t;
    buildtree(t);
    findAllAncestor(t, 'G');
    return 0;
}