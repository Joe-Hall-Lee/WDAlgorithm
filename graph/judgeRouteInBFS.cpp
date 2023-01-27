/*
    采用基于广度优先遍历算法判别以邻接表方式存储的有向图中是否存在由顶点 vi 到顶点 vj 的路径（i ≠ j）。
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

// 链队
struct Link
{
    int node; // 进行广度优先时会用到，将顶点序号入队
    struct Link *next;
};

struct LinkQueue
{
    struct Link *front, *rear;
};

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

bool isEmpty(LinkQueue *lq)
{
    return lq->front == lq->rear;
}

bool enQueue(LinkQueue *lq, int data)
{
    struct Link *newD = (struct Link *)malloc(sizeof(struct Link));
    newD->node = data;
    lq->rear->next = newD;
    lq->rear = newD;
    return true;
}

bool deQueue(LinkQueue *lq, int *data)
{
    if (isEmpty(lq))
        return false;
    struct Link *p = lq->front->next;
    *data = lq->front->next->node;
    lq->front->next = p->next;
    if (lq->rear == p)
        lq->rear = lq->front;
    free(p);
    return true;
}

// 创建一个带头结点的空链表
Link *createL()
{
    struct Link *head = (struct Link *)malloc(sizeof(struct Link));
    head->next = NULL;
    return head;
}

LinkQueue *create()
{
    struct Link *h;
    struct LinkQueue *lq = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
    h = createL();
    lq->front = lq->rear = h;
    return lq;
}

bool judgeRouteInBFS(ALGraph *G, int vi, int vj)
{
    int *visited = (int *)malloc(sizeof(int) * G->numV);
    bool flag = false; // 进入递归，路径存在标志
    int index;         // 进行判断用
    for (int i = 0; i < G->numV; i++)
        visited[i] = 0; // 初始化
    LinkQueue *lq;
    lq = create();
    if (!visited[vi])
    {
        visited[vi] = 1;
        enQueue(lq, vi); // 入队
    }
    while (!isEmpty(lq)) // 当队列不空，取出队首元素进行判断
    {
        deQueue(lq, &index);
        if (!visited[index]) // 若未曾访问过，进行判断
        {
            visited[index] = 1;
            if (vj == index)
                flag = true;
        }
        for (EdgeNode *p = G->adjlist[index].firstEdge; p; p = p->next)
        {
            if (!visited[p->index])
                enQueue(lq, p->index); // 把所有的未访问过的邻接顶点入队
        }
    }
    return flag;
}

int main()
{
    bool haveRoute;
    ALGraph G;
    createGraph(&G); // 创建图
    int vi, vj;
    printf("请输入vi，vj\n");
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
    haveRoute = judgeRouteInBFS(&G, vi - 1, vj - 1);
    if (haveRoute)
        printf("顶点 %d 到顶点 %d 存在路径", vi, vj);
    else
        printf("顶点 %d 到顶点 %d 不存在路径", vi, vj);
    return 0;
}