// 线性表中各结点的检索不等时，可用如下策略提高顺序检索的效率：若找到指定的结点，则将该结点和其前驱结点（若存在）交换，使得经常被检索的结点尽量位于表的前端。
// 试设计在顺序结构的线性表上实现上述策略的顺序检索算法。
#include <iostream>
using namespace std;

// 置前函数
int Search(int a[], int n, int k)
{
    // 遍历
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == k)
            break;
    }
    // 找到就交换，返回交换后的位置
    if (i > 0 && i < n)
    {
        int t = a[i - 1];
        a[i - 1] = a[i];
        a[i] = t;
        return i - 1;
    }
    else
        return -1;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5};
    cout << Search(a, 5, 3) << endl;
    return 0;
}