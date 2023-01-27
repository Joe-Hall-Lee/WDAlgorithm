/*
    采用基于深度优先遍历算法判别以邻接表方式存储的有向图中是否存在由顶点 vi 到顶点 vj 的路径（i ≠ j）。
    注意，算法中涉及的图的基本操作必须在此存储结构上实现。
    分析：
        从 vi 顶点开始进行深度遍历，若存在路径则必然可以走到 vj 顶点处。
*/
#include <stdlib.h>
#include <stdio.h>
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
    }
}

// visited数组
int visited[MAXSIZE] = {0};

void judgeRouteInDFS(ALGraph *G, int vi, int vj, bool &flag)
{
    // 如果当前结点就是 j 结点
    if (vi == vj)
    {
        // flag 赋值，并退出函数
        flag = true;
        return;
    }
    // 否则更新访问标记
    visited[vi] = 1;

    // 遍历邻接点，向后延伸
    for (EdgeNode *p = G->adjlist[vi].firstEdge; p; p = p->next)
    {
        if (!visited[p->index] && !flag)
            judgeRouteInDFS(G, p->index, vj, flag);
    }
}

int main()
{
    bool haveRoute;
    ALGraph G;
    createGraph(&G); // 创建图
    int vi, vj;
    printf("请输入vi、vj\n");
    printf("vi = ");
    scanf("%d", &vi);
    printf("vj = ");
    scanf("%d", &vj);
    while (vi > G.numV || vj > G.numV)
    {
        printf("输入有误，不存在该顶点，请重新输入！");
        printf("vi = ");
        scanf("%d", &vi);
        printf("vj = ");
        scanf("%d", &vj);
    }
    judgeRouteInDFS(&G, vi - 1, vj - 1, haveRoute);
    if (haveRoute)
        printf("顶点 %d 到顶点 %d 存在路径", vi, vj);
    else
        printf("顶点 %d 到顶点 %d 不存在路径", vi, vj);
    return 0;
}