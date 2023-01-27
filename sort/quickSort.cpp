// 试编写快速排序的划分算法，使之每次选取的枢轴值都是随机地从当前子表中选择的。
#include <bits/stdc++.h>
using namespace std;

int partition(int *a, int low, int high) // 该函数进行一次快速排序并返回基准元素最终所在位置
{
    // 获取随机下标
    int root = low + rand() % (high - low + 1);
    // 交换到第一个
    swap(a[low], a[root]);
    // i 一开始指向low位置
    int i = low;
    // 从第二个开始遍历到结束
    int p = a[low];
    for (int j = low + 1; j <= high; j++)
    {
        // 如果小于基准值
        if (a[j] < p)
            // 交换到前面去
            swap(a[++i], a[j]);
    }
    // 将基准元素插入到最终的位置
    swap(a[low], a[i]);
    return i; // 返回存放枢纽的最终位置
}

void quickSort(int *arr, int low, int high)
{
    if (low < high) // 子表元素个数大于一个，进行快速排序
    {
        int pivotPos = partition(arr, low, high); // 快速排序一次并获取存放枢纽的最终位置，用于划分子表
        quickSort(arr, low, pivotPos - 1);        // 左子表
        quickSort(arr, pivotPos + 1, high);       // 右子表
    }
}

int main()
{
    int arr[] = {5, 3, 4, 10, 6, 11, 12};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    return 0;
}