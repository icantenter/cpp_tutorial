#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
int main()
{
}

void prefix_table(int prefix[], size_t size);

void Get_fail() //构造fail指针
{
    queue<int> Q;                //队列
    for (int i = 0; i < 26; ++i) //第二层的fail指针提前处理一下
    {
        if (AC[0].vis[i] != 0)
        {
            AC[AC[0].vis[i]].fail = 0; //指向根节点
            Q.push(AC[0].vis[i]);      //压入队列
        }
    }
    while (!Q.empty()) //BFS求fail指针
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; ++i) //枚举所有子节点
        {
            if (AC[u].vis[i] != 0) //存在这个子节点
            {
                AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                //子节点的fail指针指向当前节点的
                //fail指针所指向的节点的相同子节点
                Q.push(AC[u].vis[i]); //压入队列
            }
            else //不存在这个子节点
                AC[u].vis[i] = AC[AC[u].fail].vis[i];
            //当前节点的这个子节点指向当
            //前节点fail指针的这个子节点
        }
    }
}