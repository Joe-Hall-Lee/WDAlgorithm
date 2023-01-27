/*
    假设一个算术表达式包含圆括号、方括号、花括号3种类型的括号，编写一个算法来判断表达式里的括号是否配对，以字符'\0'作为
    算术表达式的结束符。
    分析：
        利用数组来存储算术表达式，再利用一个栈来进行判定，具体流程为：依次从数组中取出字符，如果是左括号则入栈，
        如果是右括号则取出栈顶元素，比对是否配对，如果不匹配，终止，匹配则继续。
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
        cout << "栈满" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

int outstack(stack1 &s, char &x)
{
    if (isempty(s))
    {
        cout << "栈空" << endl;
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
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') // 如果是左括号，入栈
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
        cout << "括号不匹配" << endl;
    else
        cout << "括号匹配" << endl;
    return 0;
}
