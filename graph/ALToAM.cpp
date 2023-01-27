/*
	写出从图的邻接表表示转换成邻接矩阵表示的算法。
	分析：
		遍历邻接表中的每一个顶点，并根据边的信息，将数据填入邻接矩阵中。
*/
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100

typedef struct Graph
{
	char Vertex[MAXSIZE]; // 顶点数组
	int Edge[MAXSIZE][MAXSIZE];
	int numV, numE; // 顶点、边数量
} AMGraph;			// 邻接矩阵

// 邻接表存储的图
typedef struct EdgeNode // 边表结点
{
	int index;		// 该边所指向的顶点的位置，在顶点数组里面的位置信息
	int weight;		// 权值
	EdgeNode *next; // 下一个邻接边
} EdgeNode;

typedef struct VertexNode // 顶点表结点
{
	char info;			 // 顶点信息
	EdgeNode *firstEdge; // 指向第一条依附该顶点的边的指针
} VertexNode, Adjlist[MAXSIZE];

typedef struct
{
	Adjlist adjlist; // 顶点数组
	int numE, numV;	 // 边数、顶点数
} ALGraph;

void createGraph(ALGraph *G)
{
	int e, v, vi, vj, w;
	printf("请输入图的边数与结点数（以空格分开）: ");
	scanf("\n%d %d", &e, &v);
	G->numE = e;
	G->numV = v;
	printf("请依次输入顶点信息: \n");
	for (int i = 0; i < G->numV; i++)
	{
		printf("请输入第%d个结点信息: ", i + 1);
		scanf("\n%c", &G->adjlist[i].info);
		G->adjlist[i].firstEdge = NULL;
	}

	printf("请输入边表信息：\n");
	for (int i = 0; i < G->numE; i++)
	{
		printf("请输入边(vi, vj)的顶点序号及其权值（以空格分开）：");
		scanf("%d %d %d", &vi, &vj, &w);
		// 若是无向图则需要对两个顶点进行操作，采用头插法
		EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->index = vj - 1; // 数组下标要减一
		e->weight = w;
		e->next = G->adjlist[vi - 1].firstEdge;
		G->adjlist[vi - 1].firstEdge = e;

		EdgeNode *ed = (EdgeNode *)malloc(sizeof(EdgeNode));
		ed->index = vi - 1;
		ed->weight = w;
		ed->next = G->adjlist[vj - 1].firstEdge;
		G->adjlist[vj - 1].firstEdge = ed;
	}
}

void ALToAM(ALGraph *alG, AMGraph *amG) // 开始进行转换
{
	amG->numE = alG->numE;
	amG->numV = alG->numV;
	for (int v = 0; v < amG->numV; v++)
		amG->Vertex[v] = alG->adjlist[v].info; // 顶点信息存入邻接矩阵
	// 初始化图
	for (int i = 0; i < amG->numV; i++)
	{
		for (int j = 0; j < amG->numV; j++)
			i == j ? amG->Edge[i][j] = 0 : amG->Edge[i][j] = 32767;
	}
	for (int v = 0; v < amG->numV; v++)
	{
		// 存入边信息
		EdgeNode *p = alG->adjlist[v].firstEdge;
		while (p)
		{
			amG->Edge[v][p->index] = p->weight;
			p = p->next;
		}
	}
}

void dispGraph(AMGraph *G)
{
	int i, j;
	printf("\n输出顶点的信息（字符）:\n");
	for (i = 0; i < G->numV; i++)
		printf("%8c", G->Vertex[i]);

	printf("\n输出邻接矩阵:\n");
	printf("\t");
	for (i = 0; i < G->numV; i++)
		printf("%8c", G->Vertex[i]);

	for (i = 0; i < G->numV; i++)
	{
		printf("\n%8c", G->Vertex[i]);
		for (j = 0; j < G->numV; j++)
		{
			if (G->Edge[i][j] == 32767)
				// 两点之间无连接时权值为默认的 32767，
				// 在无向图中一般用“0”表示，在有向图中一般用“∞”,
				// 这里为了方便统一输出“∞”
				printf("%8s", "∞");
			else
				printf("%8d", G->Edge[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	ALGraph alG;
	AMGraph amG;
	createGraph(&alG); // 创建图 G
	ALToAM(&alG, &amG);
	dispGraph(&amG);
	return 0;
}