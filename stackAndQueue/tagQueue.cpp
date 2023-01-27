/*
    若希望循环队列中的元素都能得到利用，则需设置一个标志域 tag，并以 tag 的值为 0 或 1 来区分队头指针 front 和队尾指针 rear
    相同时的队列状态是“空”还是“满”。试编写此结构相应的入队和出队算法。
*/
#include <iostream>
using namespace std;
#define Max 10
typedef struct
{
    int data[Max];
    int f, r, tag;
} tagQueue;

bool enters(tagQueue &s, int x)
{
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满，进队失败" << endl;
        return false;
    }
    s.data[s.r] = x;
    cout << s.data[s.r] << " ";
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}

int outs(tagQueue &s, int &x)
{
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空，出队失败" << endl;
        return 0;
    }
    x = s.data[s.f];
    s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}

int main()
{
    tagQueue s;
    s.f = 0, s.r = 0, s.tag = 0;
    for (int i = 0; i < 10; i++)
        enters(s, i);
    cout << endl;
    enters(s, 1);
    int x = 0;
    for (int i = 0; i < 10; i++)
        outs(s, x);
    outs(s, x);
    return 0;
}
