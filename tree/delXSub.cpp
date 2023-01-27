/*
    ��֪�������Զ�������洢����д�㷨��ɣ���������ÿ��Ԫ��ֵΪ x �Ľ�㣬ɾȥ����Ϊ�������������ͷ���Ӧ�Ŀռ䡣
    ������
        ��ΪҪɾ����Ѱ�ҵ���Ԫ��Ϊ��������������ɾ��ʱӦ���õݹ�����������ɾ���ͷţ�Ѱ�� x �������������
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct treenode
{
    // ���ֵ
    char data;
    // �������Һ���ָ��
    struct treenode *lchild, *rchild;
} treenode, *tree;

// ��������ֵ���
void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        // �����ڴ�ռ�����
        t = (treenode *)malloc(sizeof(treenode));
        // ����㸳ֵ
        t->data = ch;
        // �����Һ��ӽ����Ϊ��
        t->lchild = NULL;
        t->rchild = NULL;
        // �ݹ�ȥ��ֵ�������Һ���
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// �ݹ��ͷŽ��
void Release(tree &t)
{
    if (!t)
        return;
    Release(t->lchild);
    Release(t->rchild);
    free(t);
}

// ǰ�����
void delXSub(tree &T, char x) // �ͷŽ�㺯��
{
    if (!T)
        return;
    if (T->data == x)
    {
        // �ݹ��ͷŽ��
        Release(T);
        // �ֶ�ȥ���ý��ΪNULL���������һ���ͷ�
        T = NULL;
    }
    if (T)
    {
        delXSub(T->lchild, x);
        delXSub(T->rchild, x);
    }
}

// ��ӡ
void disp(tree t)
{
    if (t)
    {
        cout << t->data << " ";
        disp(t->lchild);
        disp(t->rchild);
    }
}

// ������������
int main()
{
    tree t;
    buildtree(t); // ����һ�ö�����
    delXSub(t, 'A');
    disp(t);
    return 0;
}