/*
    从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
    空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
    分析：
        可以将顺序表看作数组，即要找出数组中最小的元素位置，并删除它，而这里删除之后我们会用最后一个元素替代它。
        综上所述，可以设置一个位置标签，遍历一次找到最小的那个元素的位置，然后直接将最后一个元素的值赋予该位置。
*/
#include <iostream>
using namespace std;
#define Max 50
struct SqList
{
    int a[Max] = {2, 3, 4, 6, 7, 1, 8, 9};
    int length = 8;
};

bool delMin(SqList &s, int &ele)
{
    if (s.length == 0)
        return false;
    int minn = s.a[0];
    int flag = 0;
    for (int i = 1; i < s.length; i++)
    {
        if (s.a[i] < minn)
        {
            minn = s.a[i];
            flag = i;
        }
    }
    ele = s.a[flag];
    s.a[flag] = s.a[s.length - 1];
    return true;
}

int main()
{
    SqList s;
    cout << "原先数组为：" << endl;
    for (int i = 0; i < s.length; i++)
        cout << s.a[i] << " ";
    cout << endl;
    int k = 0;
    if (delMin(s, k))
    {
        cout << "最小元素k = " << k << endl;
        cout << "修改之后的线性表为：" << endl;
        for (int i = 0; i < s.length; i++)
            cout << s.a[i] << " ";
        cout << endl;
    }
    else
        cout << "错误" << endl;
    return 0;
}
