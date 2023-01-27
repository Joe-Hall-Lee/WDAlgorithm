/*
    ����һ���������ʽ����Բ���š������š�������3�����͵����ţ���дһ���㷨���жϱ��ʽ��������Ƿ���ԣ����ַ�'\0'��Ϊ
    �������ʽ�Ľ�������
    ������
        �����������洢�������ʽ��������һ��ջ�������ж�����������Ϊ�����δ�������ȡ���ַ������������������ջ��
        �������������ȡ��ջ��Ԫ�أ��ȶ��Ƿ���ԣ������ƥ�䣬��ֹ��ƥ���������
*/
#include <iostream>
using namespace std;
#define Max 10
struct stack1
{
    char data[Max + 1];
    int top;
};

bool isempty(stack1 s)
{
    if (s.top == -1)
        return true;
    return false;
}

bool isfull(stack1 s)
{
    if (s.top == Max - 1)
        return true;
    return false;
}

bool enterstack(stack1 &s, char x)
{
    if (isfull(s))
    {
        cout << "ջ��" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

int outstack(stack1 &s, char &x)
{
    if (isempty(s))
    {
        cout << "ջ��" << endl;
        return 0;
    }
    x = s.data[s.top--];
    return 1;
}

bool matchBracket(char *str)
{
    stack1 s;
    s.top = -1;
    int i = 0;
    char ans;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') // ����������ţ���ջ
            enterstack(s, str[i]);
        else if (str[i] == ')')
        {
            outstack(s, ans);
            if (ans != '(')
                return false;
        }
        else if (str[i] == ']')
        {
            outstack(s, ans);
            if (ans != '[')
                return false;
        }
        else if (str[i] == '}')
        {
            outstack(s, ans);
            if (ans != '{')
                return false;
        }
        i++;
    }
    if (isempty(s))
        return true;
    return false;
}

int main()
{
    char *str = (char *)"()[](}{}()";
    cout << str << endl;
    if (!matchBracket(str))
        cout << "���Ų�ƥ��" << endl;
    else
        cout << "����ƥ��" << endl;
    return 0;
}
