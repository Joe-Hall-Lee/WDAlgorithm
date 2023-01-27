/*
    将集合A划分为A1、A2，个数分别为n1、n2，和分别为S1、S2，|n1 - n2| 最小， |S1 - S2| 最大。
        分析：|n1 - n2| 最小，意思就是平分；|S1 - S2| 最大，意思就是把值最大的那部分和值最小的那部分分开。
            利用快速排序的特性，做一些优化：当进行一次快速排序后：
            若 i == n / 2 - 1，则已将最小、最大的 n / 2 元素分开；
            若 i < n / 2 - 1，则对 i 后的元素继续划分；
            若 i > n / 2 - 1，则对 i 前的元素继续划分。
*/
#include <bits/stdc++.h>
using namespace std;

// 快排
void specialDivided(int a[], int n, int low, int high)
{
    // 非递归
    int flag = 1;
    // 取中间值，后面与基准值进行比较
    int k = n / 2;
    // 非递归条件
    while (flag)
    {
        // 快排
        //  i 一开始指向 low 位置
        int i = low;
        // 从第二个开始遍历到结束
        int p = a[low];
        for (int j = low + i; j <= high; j++)
        {
            // 如果小于基准值
            if (a[j] < p)
                // 交换到前面去
                swap(a[++i], a[j]);
        }
        // 将基准元素插入到最终的位置
        swap(a[low], a[i]);
        // 如果基准值刚好等于 s1 的右端，结束
        if (i == k - 1)
            flag = 0;
        // 如果基准值小于，则在右端进行快排，继续找到中间值的位置
        else if (i < k - 1)
            low = i + 1;
        // 否则在左端
        else
            high = i - 1;
    }
    // 计算两个集合的和
    int s1 = 0, s2 = 0;
    cout << "s1 = ";
    for (int i = 0; i < k; i++)
    {
        s2 += a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "s2 = ";
    for (int i = k; i < n; i++)
    {
        s2 += a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    cout << abs(s1 - s2) << endl;
}

int main()
{
    int a[9] = {0, -1, -2, 0, -10, 3, -4, 1};
    specialDivided(a, 8, 0, 7);
    return 0;
}