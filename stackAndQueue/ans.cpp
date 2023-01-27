/*
    ����һ��ջʵ�����µݹ麯���ķǵݹ���㡣
    ������
        ������Ҫʹ��ջ���Ƚ�������ԡ����Կ������� n = 2 ��ʼ��ÿһ��ֵ�㶼��ǰ����ֵ�ҹ�����ʽ�Ӳ��䣬���Դ�ջ����ջ�����α߳�ջ�߼��㣬����Եó����ս����
*/
#include <iostream>
using namespace std;
#define Max 10
struct stack1
{
    int n;
    double pnx;
} st[Max];

double ans(int n, double x) // ���㷨���������� n �� x
{
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--) // �������ջ���������£��� 2 �� n
    {
        top++;
        st[top].n = i;
    }
    while (top >= 0) // �߳�ջ�߼���
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