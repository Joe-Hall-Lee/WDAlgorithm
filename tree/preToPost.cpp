/*
	����һ���������������н��ֵ����ͬ������֪����������Ϊ pre�����һ���㷨����������� post��
	������
		1���ҳ��������еĸ���㣬������������������ĩβ��
		2����Ϊ�����������Ƕ԰�ֵģ��������֮��Ľڵ�ֳ��������ѣ��ٷֱ�ִ����һ����
		3��ֱ��ȫ�������ꡣ
*/
#include <iostream>
using namespace std;

// �ݹ齻������
void preToPost(char *arrPre, char *arrPost, int l1, int h1, int l2, int h2)
{
	// l1��h1��l2��h2 ���� arrPre �� arrPost ������ĩβ
	int half; // ���������ٽ�
	if (l1 <= h1)
	{
		half = (h1 - l1) / 2;
		*(arrPost + h2) = *(arrPre + l1);
		preToPost(arrPre, arrPost, l1 + 1, l1 + half, l2, l2 + half - 1); // ���
		preToPost(arrPre, arrPost, l1 + half + 1, h1, l2 + half, h2 - 1); // �ұ�
	}
}

// ������������
int main()
{
	char arrPre[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'}, arrPost[7];
	preToPost(arrPre, arrPost, 0, 6, 0, 6);
	for (int i = 0; i < 7; i++)
		printf("%c ", *(arrPost + i));
	return 0;
}