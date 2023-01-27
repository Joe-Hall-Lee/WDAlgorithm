// 写出图的深度优先搜索 DFS 算法的非递归算法（图采用邻接表形式）。
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

typedef struct EdgeNode // 边表结点
{
	int index;		// 该边所指向的顶点的位置
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

// 栈
typedef struct
{
	SElemType *base; // 栈底指针
	SElemType *top;	 // 栈顶指针
	int stacksize;	 // 栈可用最大容量
} SqStack;

Status InitStack(SqStack &S) // 构造一个空栈
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;		// 栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(SqStack &S, SElemType e)
{
	if (S.top - S.base == S.stacksize) // 栈满
		return ERROR;
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e) // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

bool StackEmpty(SqStack S) // 若栈为空，返回true，否则返回false
{
	if (S.top == S.base)
		return true;
	else
		return false;
}

void visit(ALGraph G, SElemType k)
{
	cout << G.adjlist[k].info << " ";
}

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

void dispGraph(ALGraph *G)
{
	// 将图用邻接表的形式展示出来
	for (int i = 0; i < G->numV; i++)
	{
		int j = i;
		printf("%c-->", G->adjlist[j].info);
		EdgeNode *p = G->adjlist[j].firstEdge;
		while (p)
		{
			printf("(%d)%c-->", p->weight, G->adjlist[p->index].info);
			p = p->next;
		}
		printf("^\n");
	}
}

// 非递归深度优先搜素
void DFSInAL(ALGraph &G, SElemType v)
{
	SElemType k;
	// 初始化栈
	SqStack S;
	InitStack(S);

	// 初始化visited数组
	bool visited[G.numV + 1];
	for (int i = 0; i < G.numV; i++)
		visited[i] = false;
	// 顶点压入栈中
	Push(S, v);
	visited[v] = true;
	// 顶点已经被压入过，更新visited数组
	// 退栈
	while (!StackEmpty(S))
	{
		Pop(S, k);
		// 访问该结点，访问的顺序就是DFS顺序
		visit(G, k);
		// 访问所有的邻接结点
		for (EdgeNode *p = G.adjlist[k].firstEdge; p; p = p->next)
		{
			// 没有进过栈的话进栈
			if (!visited[p->index])
			{
				Push(S, p->index);
				visited[p->index] = true;
			}
		}
	}
}

int main()
{
	ALGraph alG;
	// 创建图
	createGraph(&alG);
	// 打印图
	dispGraph(&alG);

	// 深度优先遍历
	DFSInAL(alG, 0);
	return 0;
}