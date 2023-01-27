/*
    ������������ö�������洢�ṹ�洢�������һ���㷨����������������е�k��1 <= k <= �������н�������������ֵ��
    ������
        ÿ����һ����㣬���������һ��ֱ������k��
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct biTree
{
    // ����ֵ
    char data;
    // �������Һ���ָ��
    struct biTree *lchild, *rchild;
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
        // �Խ������ڴ����
        t = (treenode *)malloc(sizeof(treenode));
        // �Խ����и�ֵ
        t->data = ch;
        // ��ʼ�������Һ��ӽ��Ϊ��
        t->lchild = NULL;
        t->rchild = NULL;
        // �ݹ�ȥ��ֵ��������
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}

// ������
int i = 1;
// �ַ�
char ch;

char preK(tree t, int k)
{
    if (!t)
        return '#';
    if (i == k) // �ҵ��󣬼�¼����
        return t->data;
    i++;
    ch = preK(t->lchild, k);
    if (ch != '#')
        return ch;
    ch = preK(t->rchild, k);
    return ch;
}

// ������������
int main()
{
    tree t;
    buildtree(t); // ����һ�ö�����
    cout << preK(t, 7) << endl;
    return 0;
}