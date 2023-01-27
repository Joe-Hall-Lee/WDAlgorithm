// ��ջ����һƬ�ڴ棬�ֱ���н�ջ�ͳ�ջ����
#include <iostream>
using namespace std;
#define Max 50
typedef struct
{
	int data[Max];
	int top[2];
} shareStack;
shareStack s;

int push(int i, int x)
{
	if (i != 0 && i != 1)
	{
		cout << "��ջ" << endl;
		return -1;
	}
	if (s.top[1] - s.top[0] == 1)
	{
		cout << "ջ��" << endl;
		return -1;
	}
	if (i == 0)
		s.data[++s.top[0]] = x;
	else
		s.data[--s.top[1]] = x;
	return 1;
}

int pop(int i)
{
	if (i != 0 && i != 1)
	{
		cout << "��ջ" << endl;
		return -1;
	}
	if (i == 0)
	{
		if (s.top[0] == -1)
		{
			cout << "0 ��ջջ��" << endl;
			return -1;
		}
		return s.data[s.top[0]--];
	}
	else
	{
		if (s.top[1] == Max)
		{
			cout << "1 ��ջջ��" << endl;
			return -1;
		}
		return s.data[s.top[1]--];
	}
}

int main()
{
	s.top[0] = -1, s.top[1] = Max;
	if (push(0, 1) != -1)
		cout << "0 ��ջ��ջ�ɹ�" << endl;
	int x = pop(0);
	if (x != -1)
	{
		cout << "0 ��ջ��ջ�ɹ� ";
		cout << "0 ��ջ��ջԪ��Ϊ��" << x << endl;
	}

	int y = pop(0);
	return 0;
}