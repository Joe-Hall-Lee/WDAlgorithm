// 设顺序表用数组 A[] 表示，表中元素存储在数组下标 1 ~ m + n 的范围内，前 m 个元素递增有序，后 n 个元素递增有序，设计一个算法，使得整个顺序表有序。
#include <iostream>
using namespace std;

void insertSort(int a[], int m, int n)
{
    // 两个遍历指针
    int i, j;
    // 第一个遍历范围
    for (int i = m + 1; i <= m + n; i++)
    {
        // 复制哨兵
        a[0] = a[i];
        for (j = i - 1; a[j] > a[0]; j--)
            // 后移
            a[j + 1] = a[j];
        // 插入哨兵值
        a[j + 1] = a[0];
    }
}

int main()
{
    int a[8] = {0, 1, 3, 5, 7, 2, 4, 9};
    insertSort(a, 4, 3);
    for (int i = 1; i <= 7; i++)
        cout << a[i] << " ";
    return 0;
}