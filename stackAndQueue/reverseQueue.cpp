/*
    ��һ�����к�һ��ջ�����һ���㷨ʹ�����е�Ԫ�����á�
    ������
        һ��ȡ�������е�Ԫ�طŵ�ջ�У�Ȼ������ȡ����ӡ�
*/
#include <iostream>
using namespace std;
#define Max 10
struct stack1
{
    int data[Max];
    int top;
};
struct squeue1
{
    int data[Max];
    int r, f, tag;
};

bool entersqueue(squeue1 &s, int x)
{
    if (s.f == s.r && s.tag == 1)
    {
        cout << "���� ����ʧ��" << endl;
        return false;
    }
    s.data[s.r] = x;
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}

int outsqueue1(squeue1 &s, int &x)
{
    if (s.f == s.r && s.tag == 0)
    {
        cout << "�ӿ� ����ʧ��" << endl;
        return 0;
    }
    x = s.data[s.f];
    s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}

bool enterstack(stack1 &s, int x)
{
    if (s.top == Max - 1)
    {
        cout << "ջ�� ��ջʧ��" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

int outstack(stack1 &s, int &x)
{
    if (s.top == -1)
    {
        cout << "ջ�� ��ջʧ��" << endl;
        return 0;
    }
    x = s.data[s.top--];
    return 1;
}

void disp(squeue1 s)
{
    for (int i = 0; i < Max; i++)
    {
        cout << s.data[s.f] << " ";
        s.f = (s.f + 1) % Max;
    }
    cout << endl;
}

int main()
{
    squeue1 s1;
    stack1 s2;
    s1.f = 0, s1.r = 0, s1.tag = 0;
    s2.top = -1;
    for (int i = 0; i < Max; i++)
        entersqueue(s1, i);
    disp(s1);
    int x = 0;
    while (!(s1.f == s1.r && s1.tag == 0))
    {
        outsqueue1(s1, x);
        enterstack(s2, x);
    }
    while (!(s2.top == -1))
    {
        outstack(s2, x);
        entersqueue(s1, x);
    }
    disp(s1);
    return 0;
}
