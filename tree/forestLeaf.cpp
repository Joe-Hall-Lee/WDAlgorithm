/*
    ������Ժ����ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽ������
    ������
        ���һ����������ӣ���ô���ݺ����ֵܱ�ʾ���Ĺ�������һ������Ҷ�ӽ�㣬�෴�����û�����ӣ���ô
        ��һ����Ҷ�ӽ�㣬���Һ��Ӽ������ֵܣ�ͬ��Ӧ������ȥ�жϡ�
*/
#include <iostream>
using namespace std;
// �ṹ��
typedef struct treenode
{
    // ���ֵ
    char data;
    // ���������ֵ���ָ��
    struct treenode *child, *rbro;
} treenode, *tree;

// ����
void buildtree(tree &t) // ���򴴽�һ�ö�����
{
    char ch;
    cin >> ch;
    if (ch == '#')
        t = NULL;
    else
    {
        // �����ڴ�
        t = (treenode *)malloc(sizeof(treenode));
        // ��ֵ
        t->data = ch;
        // ��ʼ��
        t->child = NULL;
        t->rbro = NULL;
        // �ݹ鸳ֵ
        buildtree(t->child);
        buildtree(t->rbro);
    }
}

// �ݹ���Ҷ�ӽ��
int forestLeaf(tree t)
{
    // �ս�㣬����0
    if (!t) // ���򷵻�0��Ҳ�ǵݹ�ĳ���
        return 0;
    // ����Ϊ�ռ�������Ϊ�գ�ΪҶ�ӽ�㣬�����1��Ҫ�������ֵ�������Ҷ�ӽ��
    if (!t->child) // û�����ӣ��ý��ΪҶ�ӽ��
        return 1 + forestLeaf(t->rbro);
    else // �����ӣ��ý�㲻��Ҷ�ӽ��
        return forestLeaf(t->child) + forestLeaf(t->rbro);
}

// ����������
int main()
{
    tree t;
    buildtree(t);
    cout << forestLeaf(t) << endl;
    return 0;
}