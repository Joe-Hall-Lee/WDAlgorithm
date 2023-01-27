/*
    编写一个算法，使之能够在数组中找到第k小的元素。
        分析：采用快速排序来，快速排序每一趟会确定一个元素的最终位置，假设为 m：
            若 m = k，那么此时便找到了第 k 小的元素；
            若 m < k ,说明第 k 小的元素在 m 的右半部分，继续查找第 k 小元素；
            若 m > k，说明第 k 小的元素在 m 的左半部分，继续查找第 k 小元素；
            该算法的平均时间复杂度为 O(n)。
*/
#include <iostream>
using namespace std;

// 快速排序划分算法
int findKthInSq(int a[], int low, int high, int k)
{

    // i 一开始指向 low 位置
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
    // 若最后基准的位置为 k，那么基准就是第 k 小
    if (i = k)
        return a[i];
    // 若最后基准的位置 > k，则在基准左边递归去找
    else if (i > k)
        return findKthInSq(a, low, i - 1, k);
    // 若最后基准的位置 < k，则在基准右边递归去找
    else
        return findKthInSq(a, i + 1, high, k);
}

int main()
{
    int a[10] = {0, 7, 5, 9, 2, 6, 4, 3, 8, 1};
    cout << findKthInSq(a, 1, 9, 8);
    return 0;
}