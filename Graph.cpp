#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
typedef int InfoType;
typedef char VertexType;
#define MAX_VERTEX_NUM 20
using namespace std;


typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    InfoType info;

} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;

void dfs(ALGraph G, int x);
void bfs(ALGraph G, int x);
std::vector<int> adj(ALGraph G, int x);
void addEdge(ALGraph &G, int v, int w, int a);
int *marked;
int distance[MAX_VERTEX_NUM];

int main()
{
    ALGraph G;
    marked = new int[G.vexnum];
    memset(marked, 0, sizeof(int) * G.vexnum);

    std::cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++) 
    {
        G.vertices[i].firstarc = NULL;
    }
    
    for (int i = 0; i < G.arcnum; i++)
    {
        int v, w, a;
        std::cin >> v >> w >> a;
        addEdge(G, v, w, a);
        addEdge(G, w, v, a);
    }
    
    // dfs(G, 0);
    bfs(G, 0);
    std::cout << ">";
    return 0;
}

void bfs(ALGraph G, int x)
{
    std::queue<int> nodes;

    nodes.push(x);
    memset(marked, 0, sizeof(int) * G.vexnum);
    while (nodes.size())
    {
        int tmp = nodes.front();

        nodes.pop();
        marked[tmp] = 1;
        std::cout << tmp << std::endl;
        for (auto &&v : adj(G, tmp))
        {
            if (!marked[v])
                nodes.push(v);
        }
        
    }


}

void dijkstra(ALGraph G)
{
    std::priority_queue<node> 
}

void dfs(ALGraph G, int x)
{
    

    for (auto &&v : adj(G, x))
    {
        if (!marked[v])
        {
            marked[v] = 1;
            std::cout << v << std::endl;
            dfs(G, v);
        }
        
        
    }
    //cout << x << endl;
    
}

std::vector<int> adj(ALGraph G, int x)
{
    std::vector<int> nodes;
    ArcNode *tmp = G.vertices[x].firstarc;
    while (tmp != NULL)
    {
        nodes.push_back(tmp->adjvex);
        tmp = tmp->nextarc;
    }
    return nodes;
}

void addEdge(ALGraph &G, int v, int w, int a)
{
    ArcNode *next = G.vertices[v].firstarc;
    ArcNode *prev = NULL;
    if (!next)
    {
        G.vertices[v].firstarc = new ArcNode;
        G.vertices[v].firstarc->adjvex = w;
        //cout << v << " " << w << endl;
        G.vertices[v].firstarc->nextarc = NULL;
        G.vertices[v].firstarc->info = a;
        //cout << G.vertices[v].firstarc->adjvex << endl;
        return;
    }
    

    while (next)
    {
        prev = next;
        next = next->nextarc;
    }
    prev->nextarc = new ArcNode;
    prev->nextarc->adjvex = w;
    prev->nextarc->nextarc = NULL;
    prev->nextarc->info = a;
}

/*
6
5
0 1 1
2 3 2
0 3 3
1 4 4
0 5 5
 */