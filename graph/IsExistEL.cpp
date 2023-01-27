// �ж�ͼ�Ƿ��� EL ·��
#include <iostream>
using namespace std;

// �ڽӾ���洢�Ľṹ��
typedef struct
{
	int numVertices, numEdges; // ���㡢������
	char VerticesList[6];
	int Edge[6][6];
} MGraph;

int IsExistEL(MGraph G)
{
	// �����ͽ������
	int degree, count = 0;

	// �����ڽӾ������α���ÿ��
	for (int i = 0; i < G.numVertices; i++)
	{
		// ÿ�ж�����ʼ��Ϊ 0
		degree = 0;
		// ��������
		for (int j = 0; j < G.numVertices; j++)
			// �����ۼ�
			degree += G.Edge[i][j];
		// ����+1
		if (degree % 2 != 0)
			count++;
	}
	// 0 ���� 2 ���Ǵ���
	if (count == 0 || count == 2)
		return 1;
	// ���򲻴���
	else
		return 0;
}

// ����
int main()
{
	MGraph G;
	G.numVertices = 5;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> G.Edge[i][j];
	cout << IsExistEL(G) << endl;
	return 0;
}