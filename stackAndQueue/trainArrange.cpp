/*
	����ջ���г�����ȣ�ʹ����ȫ��λ��Ӳ��ǰ�档
	������
		��Ӳ���ݴ棬�������ȳ�ȥ��Ϊģ���г���λ�����ǲ��������������洢������AΪ��ڴ��𳵣�����BΪ���ڴ��𳵣�
		A ������������ջ����ΪӲ����ѹ��ջ����Ϊ������ֱ�ӽ���B �����ջ��Ԫ��ȫ����ջ���� B�����ˣ����Ҫ��
*/
#include <iostream>
using namespace std;
#define Max 10
struct stack1
{
	char data[Max];
	int top;
};

bool isempty(stack1 s)
{
	if (s.top == -1)
		return true;
	return false;
}

bool isfull(stack1 s)
{
	if (s.top == Max - 1)
		return true;
	return false;
}

bool enterstack(stack1 &s, char x)
{
	if (isfull(s))
	{
		cout << "ջ��" << endl;
		return false;
	}
	s.data[++s.top] = x;
	return false;
}

void outstack(stack1 &s, char &x)
{
	if (isempty(s))
		cout << "ջ��" << endl;
	else
		x = s.data[s.top--];
}

void trainArrange(char str[]) // ������ڳ���
{
	stack1 s;
	s.top = -1;
	char ans[Max + 1]; // ���ڳ���
	int j = 0;
	for (int i = 0; i < Max; i++)
	{
		if (str[i] == 'H')
			enterstack(s, str[i]); // Ӳ������ջ
		else
			ans[j++] = str[i];
	}
	char c;
	while (!isempty(s))
	{
		outstack(s, c);
		ans[j++] = c;
	}
	for (int i = 0; i < Max; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	char str[Max + 1] = "HSHSHHHSHS";
	cout << str << endl;
	trainArrange(str);
	return 0;
}
