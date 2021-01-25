#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int h[N], ne[N], e[N], w[N], idx;
int dis[N];
int pre[N];
int vis[N];
int id[N];
struct node
{
    int id, dis;
    node(int a, int b) : id(a), dis(b) {}
    bool operator<(const node &A) const { return dis > A.dis; }
};

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<node> q;
    q.push(node(1, 0));
    dis[1] = 0;
    int num = 0;
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (vis[u.id])
            continue;
        vis[u.id] = 1;
        id[u.id] = ++num;
        for (int i = h[u.id]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[u.id] + w[i])
            {
                dis[j] = dis[u.id] + w[i];
                q.push(node(j, dis[j]));
                pre[j] = u.id;
            }
        }
    }
}

void print_path(int u)
{
    if (u == 1)
    {
        printf("%c", u + 'a' - 1);
        return;
    }
    print_path(pre[u]);
    printf(" %c", u + 'a' - 1);
}

int main()
{
    memset(h, -1, sizeof h);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char a[2], b[2];
        int c;
        scanf("%s %s", a, b);
        scanf("%d", &c);
        int num1 = a[0] - 'a' + 1;
        int num2 = b[0] - 'a' + 1;
        //cout << num1 << " " << num2 << endl;
        add(num1, num2, c);
    }
    dijkstra();
    for (int i = 1; i <= 7; i++)
    {
        printf("±ß³¤£º%d  ´ÎÐò£º %d\n", dis[i], id[i]);
        cout << "---- ";
        print_path(i);
        printf("\n");
    }
    system("pause");
    return 0;
}
/*
12
a b 15
a c 2
a d 12
c e 8
c f 4
d c 24
f d 5
b e 6
d g 3
f g 10
e g 9
g b 4
*/
