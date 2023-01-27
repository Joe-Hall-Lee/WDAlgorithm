// 试说明利用 DFS 如何实现有向无环图拓补排序。
#include <iostream>
using namespace std;
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

void visit(ALGraph G, int k)
{
    cout << G.adjlist[k].info << " ";
}

int finishtime[MAXSIZE], time;

// 访问的标记数组
bool visited[MAXSIZE];

void DFS(ALGraph G, int v)
{
    // 访问当前结点
    visited[v] = true;
    visit(G, v);

    // 深度遍历邻接结点
    for (EdgeNode *p = G.adjlist[v].firstEdge; p; p = p->next)
    {
        if (!visited[p->index])
            DFS(G, p->index);
    }

    // 时间存储
    time++;
    finishtime[v] = time;
}

void topologicalSort(ALGraph G)
{
    // 初始化标记数组
    for (int i = 0; i < G.numV; i++)
        visited[i] = false;
    // 初始化时间
    time = 0;
    // DFS 每个没有被访问过的结点
    for (int v = 0; v < G.numV; v++)
    {
        if (!visited[v])
            DFS(G, v);
    }
}

int main()
{
    ALGraph G;
    createGraph(&G); // 创建图
    dispGraph(&G);
    topologicalSort(G);
    return 0;
}