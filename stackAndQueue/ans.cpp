/*
    利用一个栈实现以下递归函数的非递归计算。
    分析：
        这里需要使用栈的先进后出特性。可以看出，从 n = 2 开始，每一个值便都与前两个值挂钩，且式子不变，可以从栈顶到栈底依次边出栈边计算，便可以得出最终结果。
*/
#include <iostream>
using namespace std;
#define Max 10
struct stack1
{
    int n;
    double pnx;
} st[Max];

double ans(int n, double x) // 该算法函数，传入 n 和 x
{
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--) // 将序号入栈，从上至下，从 2 到 n
    {
        top++;
        st[top].n = i;
    }
    while (top >= 0) // 边出栈边计算
    {
        st[top].pnx = 2 * x * fv2 - 2 * (st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].pnx;
        top--;
    }
    if (n == 0)
        return fv1;
    return fv2;
}

int main()
{
    double ans1 = ans(3, 1.9);
    cout << ans1 << endl;
    return 0;
}