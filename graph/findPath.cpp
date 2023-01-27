/*
    假设图用邻接表表示，设计一个算法，输出从顶点 vi 到顶点 vj 的所有简单路径。
    分析：
        为了输出路径，需要额外添加一个 path 数组，
        用来存储 vi 到 vj 的路径数据，方便之后打印输出，采用深度优先遍历。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

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

void print(ALGraph *G, int *path, int d)
{
    for (int i = 0; i <= d; i++)
        printf("%c ", G->adjlist[path[i]].info);
    printf("\n");
}

void findPath(ALGraph *G, int vi, int vj, int *path, int *visited, int d)
{
    EdgeNode *p;
    d++;
    path[d] = vi;
    if (vi == vj)
    {
        print(G, path, d);
        return; // 因为只需要简单路径，找到则返回
    }
    visited[vi] = 1;
    for (p = G->adjlist[vi].firstEdge; p; p = p->next)
    {
        if (!visited[p->index])
            findPath(G, p->index, vj, path, visited, d);
    }
    visited[vi] = 0; // 重新置位可访问
}

int main()
{
    ALGraph G;
    createGraph(&G); // 创建图
    int vi, vj;
    printf("请输入vi、vj\n");
    printf("vi= ");
    scanf("%d", &vi);
    printf("vj= ");
    scanf("%d", &vj);
    while (vi > G.numV || vj > G.numV)
    {
        printf("输入有误，不存在该顶点，请重新输入！");
        printf("vi= ");
        scanf("%d", &vi);
        printf("vj= ");
        scanf("%d", &vj);
    }
    int *visited = (int *)malloc(sizeof(int) * G.numV);
    int *path = (int *)malloc(sizeof(int) * G.numV);
    for (int i = 0; i < G.numV; i++)
    {
        visited[i] = 0; // 初始化
        path[i] = -1;   // 初始化
    }
    dispGraph(&G);
    findPath(&G, vi - 1, vj - 1, path, visited, -1);
    return 0;
}