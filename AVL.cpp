#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

struct node
{
    int value;  //值
    int size;   //子树大小，本身节点数加上左右子树的节点数
    int key;    //用于平衡的数值，以下胡乱称平衡因子
    int num;    //值为value的节点个数，即有重复值
    int l, r;   //左右儿子的编号存储
}tr[N];
int idx;
int root;

void pushup(int u)  //更新子树大小
{
    tr[u].size = tr[tr[u].l].size + tr[tr[u].r].size + tr[u].num;
}

int get_node(int value) //创建新节点
{
    int u = ++ idx;     //新节点的地址
    tr[u].value = value;    //节点值赋值
    tr[u].num = 1;  
    tr[u].size = 1; //节点初始状态
    tr[u].key = rand(); //利用随机数求平衡因子
    return u;
}

void zig(int &p)    //右旋
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}

void zag(int &p)    //左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l);
    pushup(p);
}

void build()    //初始化平衡树，创建哨兵
{
    get_node(-100000000);
    get_node(100000000);
    root = 1;
    tr[1].r = 2;
    pushup(1);
    if(tr[1].key < tr[2].key) zag(root);
}

void insert(int &p, int value)  //插入节点
{
    if(!p) p = get_node(value); //当递归到为0的时候，说明原树上没有值为value的节点，创建
    else if(tr[p].value == value) tr[p].num ++; //存在，则直接加1
    else if(tr[p].value > value)    //该值小于该节点的值，插入左子树
    {
        insert(tr[p].l, value);
        if(tr[tr[p].l].key > tr[p].key) zig(p); //如果插入完后，左子树平衡因子大于该节点的平衡因子，进行右旋将左子树的根节点旋转到p处
    }
    else
    {
        insert(tr[p].r, value);
        if(tr[tr[p].r].key > tr[p].key) zag(p); //同理
    }
    pushup(p);  //每次插入更新大小
}

void Delete(int &p, int value)
{
    if(!p) return ;
    else if(tr[p].value == value) //找到该节点
    {
        if(tr[p].num > 1)   //数目大于1，直接减去
        {
            tr[p].num --;
        }
        else if(tr[p].l || tr[p].r)
        {
            if(!tr[p].r || tr[tr[p].l].key > tr[tr[p].r].key)
            {
                zig(p);
                Delete(tr[p].r, value);
            }
            else if(!tr[p].l || tr[tr[p].r].key > tr[tr[p].l].key)
            {
                zag(p);
                Delete(tr[p].l, value);
            }
        }
        else p = 0;
    }
    else if(tr[p].value > value) Delete(tr[p].l, value);
    else Delete(tr[p].r, value);

    pushup(p);
}

int get_rank_by_value(int p, int value) 
{
    if(!p) return 0;
    else if(tr[p].value == value) return tr[tr[p].l].size + 1;
    else if(tr[p].value > value) return get_rank_by_value(tr[p].l, value);
    else return tr[tr[p].l].size + tr[p].num + get_rank_by_value(tr[p].r, value);
}

int get_value_by_rank(int p, int rank)
{
    if(!p) return INT_MAX;
    else if(tr[tr[p].l].size >= rank) return get_value_by_rank(tr[p].l, rank);
    else if(tr[tr[p].l].size + tr[p].num >= rank) return  tr[p].value;
    else return get_value_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].num);
}

int get_prev(int p, int value)
{
    if(!p) return -INT_MAX;
    if(tr[p].value >= value) return get_prev(tr[p].l, value);
    else return max(tr[p].value, get_prev(tr[p].r, value));
}

int get_next(int p, int value)
{
    if(!p) return INT_MAX;
    if(tr[p].value <= value) return get_next(tr[p].r, value);
    else return min(tr[p].value, get_next(tr[p].l, value));
}

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    build();
    while(n --) {
        int op;
        int x;
        scanf("%d%d", &op, &x);
        if(op == 1) insert(root, x);
        else if(op == 2) Delete(root, x);
        else if(op == 3) printf("%d\n", get_rank_by_value(root, x) - 1);
        else if(op == 4) printf("%d\n", get_value_by_rank(root, x + 1));
        else if(op == 5) printf("%d\n", get_prev(root, x));
        else printf("%d\n", get_next(root, x));
    }    
    system("pause");
    return 0;
}

/*
8
1 10
1 20
1 30
3 20
4 2
2 10
5 25
6 -1
*/