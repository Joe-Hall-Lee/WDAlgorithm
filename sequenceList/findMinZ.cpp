// 找出最小的未出现的正整数
#include <iostream>
using namespace std;
int a[4] = {-5, 3, 2, 3};
int n = 4;

int findMinZ(int a[])
{
	int *b = new int[n + 2];
	for (int i = 0; i < n + 2; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] <= n + 1)
			b[a[i]] = 1;
	}
	int ans = 0;
	for (int i = 1; i < n + 2; i++)
	{
		if (b[i] == 0)
		{
			ans = i;
			break;
		}
	}
	delete[] b;

	return ans;
}

int main()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << findMinZ(a) << endl;
	return 0;
}