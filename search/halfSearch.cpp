// 折半查找的递归实现
#include <iostream>
using namespace std;

typedef struct
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int length = 8;
} ST;

int halfSearch(ST s, int ans, int low, int high)
{
    // 递归条件
    if (low > high)
        return 0;
    // 求出中间下标
    int mid = (low + high) / 2;
    // 中间值小了，到右边进行查找
    if (ans > s.a[mid])
        return halfSearch(s, ans, mid + 1, high);
    // 中间值大了，到左边进行查找
    else if (ans < s.a[mid])
        return halfSearch(s, ans, low, mid - 1);
    else
        return mid;
}

int main()
{
    ST s;
    cout << halfSearch(s, 10, 1, 8) << endl;
    return 0;
}