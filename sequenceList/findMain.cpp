// 寻找主元素
#include <iostream>
using namespace std;
int a[8] = {0, 5, 5, 3, 5, 7, 5, 5};
int a1[8] = {0, 5, 5, 3, 5, 1, 5, 7};
int n = 8;

bool findMain(int a[], int &cc)
{
	int c = a[0], count = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == c)
			count++;
		else
		{
			if (count > 0)
				count--;
			else
			{
				c = a[i];
				count = 1;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == c)
			k++;
	}
	if (k > n / 2)
	{
		cc = c;
		return true;
	}
	else
		return false;
}

int main()
{
	int cc;
	if (findMain(a, cc))
		cout << "主元素为" << cc << endl;
	else
		cout << "-1" << endl;

	return 0;
}