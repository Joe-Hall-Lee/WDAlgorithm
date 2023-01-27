/*
    ��ϣ��ѭ�������е�Ԫ�ض��ܵõ����ã���������һ����־�� tag������ tag ��ֵΪ 0 �� 1 �����ֶ�ͷָ�� front �Ͷ�βָ�� rear
    ��ͬʱ�Ķ���״̬�ǡ��ա����ǡ��������Ա�д�˽ṹ��Ӧ����Ӻͳ����㷨��
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
        cout << "����������ʧ��" << endl;
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
        cout << "�ӿգ�����ʧ��" << endl;
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
