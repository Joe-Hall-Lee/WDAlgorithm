/*
    试设计一个算法，判断一个数据序列是否构成一个小根堆。
    分析：
        小根堆的特性就是根结点小于左右孩子结点，对于一个序列将它看成完全二叉树，依次遍历，对每个结点进行判断。
        若有一个结点小于它的父亲结点则该序列不是小根堆，注意讨论单分支结点。
*/
#include <iostream>
using namespace std;

// 判断是不是小根堆
int judgeMinHeap(int a[], int len)
{
    // 最后的序号为偶数
    if (len % 2 == 0)
    {
        // 判断单分支结点
        if (a[len / 2] > a[len])
            return 0;
        // 判断双分支结点
        for (int i = len / 2 - 1; i >= 1; i--)
        {
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
                return 0;
        }
    }
    // 为奇数
    else
    {
        for (int i = len / 2; i >= 1; i--)
        {
            // 判断双分支结点
            if (a[i] > a[2 * i] || a[i] > a[i * 2 + 1])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int a[8] = {1, 1, 3, 2, 5, 4, 0};
    cout << judgeMinHeap(a, 6) << endl;
    return 0;
}