// 判断图是否有 EL 路径
#include <iostream>
using namespace std;

// 邻接矩阵存储的结构体
typedef struct
{
	int numVertices, numEdges; // 顶点、边数量
	char VerticesList[6];
	int Edge[6][6];
} MGraph;

int IsExistEL(MGraph G)
{
	// 度数和结果变量
	int degree, count = 0;

	// 遍历邻接矩阵，依次遍历每行
	for (int i = 0; i < G.numVertices; i++)
	{
		// 每行度数初始化为 0
		degree = 0;
		// 遍历该行
		for (int j = 0; j < G.numVertices; j++)
			// 度数累加
			degree += G.Edge[i][j];
		// 奇数+1
		if (degree % 2 != 0)
			count++;
	}
	// 0 或者 2 就是存在
	if (count == 0 || count == 2)
		return 1;
	// 否则不存在
	else
		return 0;
}

// 测试
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