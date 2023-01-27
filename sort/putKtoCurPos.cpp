/*
    有一数组存放着无序序列 K1, K2, K3, ..., Kn，现要求将 Kn 放在将元素排序后的正确位置上，试编写实现该功能的算法，
    要求比较关键字的次数不超过 n。
    分析：
        要求比较关键字的次数不超过 n，首选快速排序，快速排序每一次可以确定一个元素的最终位置，既然要确定 Kn 的位置，那就把 Kn 最为枢纽元素，进行一次快速
        排序，Kn 的位置也就确定了。
*/
#include <iostream>
using namespace std;

int putKtoCurPos(int a[], int low, int high)
{
    // i 一开始指向 high 位置
    int i = high;
    // 从倒数第二个开始遍历到头
    int p = a[high];
    for (int j = high - 1; j >= 0; j--)
    {
        // 如果大于基准值
        if (a[j] > p)
            // 交换到后边去
            swap(a[--i], a[j]);
    }
    // 将基准元素插入到最终的位置
    swap(a[high], a[i]);
    // 返回基准元素的位置
    return i;
}

int main()
{
    int a[5] = {3, 5, 7, 2, 4};
    cout << putKtoCurPos(a, 0, 4);
    return 0;
}