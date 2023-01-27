/*
    双向冒泡排序：
        所谓双向，即两个方向同时进行排序操作，可以在一定程度上降低时间开销。
        从左向右大值往下沉，从右往左小值往上冒，需要的遍历次数为元素个数的一半。
*/
#include <bits/stdc++.h>
using namespace std;

// 双向冒泡
void biBubbleSort(int a[], int n)
{
    // 范围的左右两端
    int low = 0, high = n - 1;
    // 一趟是否交换过初始化
    bool flag = true;
    // 循环条件：左端 < 右端并且一趟有交换
    while (low < high && flag)
    {
        // 排序前，默认一趟没有交换
        flag = false;
        // 从前向右交换
        for (int i = low; i < high; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        high--;
        // 从头向前交换
        for (int i = high; i > low; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = true;
            }
        }
        low++;
    }
}

int main()
{
    int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
    biBubbleSort(a, 9);
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    return 0;
}