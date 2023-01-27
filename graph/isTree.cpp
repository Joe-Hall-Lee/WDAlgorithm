/*
    设计一个算法，判断一个无向图 G 是否是一棵树。若是一棵树，则算法返回 true，否则返回 false。
    分析：
        是树的前提，首先该无向图必须是连通的，且边数不能过多，只能是 n - 1 条边。
        那么可以通过深度优先遍历来统计该无向图的边数与顶点数，符合条件则为一棵树。
*/
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100

// 邻接表存储的图
typedef struct EdgeNode // 边表结点
{
    int index;      // 该边所指向的顶点的位置
    int weight;     // 权值
    EdgeNode *next; // 下一个邻接边
} EdgeNode;

typedef struct VertexNode // 顶点表结点
{
    char info;           // 顶点信息
    EdgeNode *firstEdge; // 指向第一条依附该顶点的边的指针
} VertexNode, Adjlist[MAXSIZE];

typedef struct
{
    Adjlist adjlist; // 顶点数组
    int numE, numV;  // 边数、顶点数
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

void DFS(ALGraph *G, int *visited, int &numV, int &numE, int index)
{
    visited[index] = 1; // 标记为已访问
    numV++;             // 顶点数加一
    for (EdgeNode *p = G->adjlist[index].firstEdge; p; p = p->next)
    {
        numE++;
        if (!visited[p->index])
        {
            DFS(G, visited, numV, numE, p->index);
        }
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

// 判断是否是树
bool isTree(ALGraph *G)
{
    int numV = 0, numE = 0; // 统计边和顶点
    int *visited = (int *)malloc(sizeof(int) * G->numV);
    for (int i = 0; i < G->numV; i++)
        *(visited + i) = 0;         // 标记数组初始化
    DFS(G, visited, numV, numE, 0); // 只进行一次遍历
    if (numV == G->numV && numE == 2 * (G->numV - 1))
        return true;
    else
        return false;
}

int main()
{
    ALGraph G;
    bool Tree;
    createGraph(&G); // 创建图
    dispGraph(&G);
    Tree = isTree(&G);
    if (Tree)
        printf("这是一棵树");
    else
        printf("这不是一棵树");
    return 0;
}