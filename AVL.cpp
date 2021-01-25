#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

struct node
{
    int value;  //value
    int size;   //number of node
    int key;    //sort
    int num;    //number of same value
    int son[2]; //1 represent right child, 0 .....
}tr[N];
int idx;
int root;

void pushup(int u)  //update size of subtree
{
    tr[u].size = tr[tr[u].son[0]].size + tr[tr[u].son[1]].size + tr[u].num;
}

void zig(int q)
{
    int p = tr[q].son[0];
    tr[q].son[0] = tr[p].son[1];
    tr[p].son[1] = q;
    pushup(q);
    pushup(p);
}

void zag(int q)
{
    int p = tr[q].son[1];
    tr[q].son[1] = tr[p].son[0];
    tr[p].son[0] = q;
    pushup(q);
    pushup(p);
}

int build(int root, int value)
{

}

int get_node(int value)
{
    int u = ++ idx;
    tr[u].value = value;
    tr[u].key = rand();
    tr[u].size = 1;
    tr[u].num = 1;
    return u;
}

void insert(int &p, int value)
{
    if(!p) p = get_node(value);
    else if(tr[p].value == value) tr[p].num ++;
    else if(tr[p].value > value) insert(tr[p].son[1], value);
    else insert(tr[p].son[0], value);
}

void Delete(int &p, int value)
{
    if(tr[p].value == value)
    {
        if(tr[p].num > 1)
        {
            tr[p].num --;
        }
        
    }
    else if(tr[p].value > value)
    {

    }
    else if(tr[p].value < value)
    {

    }
}

int main()
{
    srand(time(NULL));
    build(root, -1000000);
    build(root, 1000000);
    
    return 0;
}