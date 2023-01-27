/*
	利用栈进行车厢调度，使软座全部位于硬座前面。
	分析：
		将硬座暂存，让软座先出去。为模拟列车座位，我们采用两个数组来存储，数组A为入口处火车，数组B为出口处火车，
		A 内数据依次入栈，若为硬座则压入栈，若为软座则直接进入B ，最后栈内元素全部出栈，入 B，至此，完成要求。
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
		cout << "栈满" << endl;
		return false;
	}
	s.data[++s.top] = x;
	return false;
}

void outstack(stack1 &s, char &x)
{
	if (isempty(s))
		cout << "栈空" << endl;
	else
		x = s.data[s.top--];
}

void trainArrange(char str[]) // 传入入口车厢
{
	stack1 s;
	s.top = -1;
	char ans[Max + 1]; // 出口车厢
	int j = 0;
	for (int i = 0; i < Max; i++)
	{
		if (str[i] == 'H')
			enterstack(s, str[i]); // 硬座，入栈
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
