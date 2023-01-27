/*
	汽车轮渡，要求：每次10辆，客车优先于货车，每上4辆客车才能上1辆货车，客车不足4辆时，货车代替。
	货车不足时，允许客车都上。
	分析：
		这仍然是一类排序的问题，将客车和货车分为两个队列，客车队列出4辆，紧接着货车
		队列出一辆；当出现客车不足时，出货车队列代替，当货车不足时，继续出客车队列。
*/
#include <iostream>
using namespace std;
#define Max 10
struct squeue
{
	int data[Max];
	int f, r, tag;
};

bool isempty(squeue s)
{
	if (s.f == s.r && s.tag == 0)
		return true;
	return false;
}

bool isfull(squeue s)
{
	if (s.f == s.r && s.tag == 1)
		return true;
	return false;
}

bool entersqueue(squeue &s, int x)
{
	if (isfull(s))
		return false;
	s.data[s.r] = x;
	s.r = (s.r + 1) % Max;
	s.tag = 1;
	return true;
}

bool outsqueue(squeue &s, int &x)
{
	if (isempty(s))
		return false;
	x = s.data[s.f];
	s.f = (s.f + 1) % Max;
	s.tag = 0;
	return true;
}

void disp(squeue &s)
{
	while (!isempty(s))
	{
		cout << s.data[s.f] << " ";
		s.f = (s.f + 1) % Max;
		s.tag = 0;
	}
	cout << endl;
}

void manageCar()
{
	squeue ans, k, h;
	ans.f = ans.r = ans.tag = 0;
	k.f = k.r = k.tag = 0;
	h.f = h.r = h.tag = 0;
	for (int i = 0; i < Max; i++)
	{
		entersqueue(k, 1);
		entersqueue(h, 2);
	}
	int i = 0, j = 0, x;
	while (j < 10)
	{
		if (!isempty(k) && i < 4)
		{
			outsqueue(k, x);
			entersqueue(ans, x);
			i++;
			j++;
		}
		else if (i == 4 && !isempty(h))
		{
			outsqueue(h, x);
			entersqueue(ans, x);
			j++;
			i = 0;
		}
		else
		{
			while (j < 10 && i < 4 && !isempty(h))
			{
				outsqueue(h, x);
				entersqueue(ans, x);
				i++;
				j++;
			}
		}
		if (isempty(k) && isempty(h))
			j = 11;
	}
	cout << "客车队列" << endl;
	disp(k);
	cout << "货车队列" << endl;
	disp(h);
	cout << "目标队列" << endl;
	disp(ans);
}

int main()
{
	manageCar();
	return 0;
}