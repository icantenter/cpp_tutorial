#include<bits/stdc++.h>
using namespace std;
struct node
{
    char val;
    node* l, *r;
    node(char val = ' ', node * l = NULL, node * r = NULL):val(val), l(l), r(r){}
};
char pre[20];
char post[20];
char mid[20];

void build_tree(node *&root, int &t, int l, int r)  
{
    int flag = -1;
    for(int i = l;i <= r;i ++)
    {
        if(post[t] == mid[i])
        {
            flag = i;break;
        }
    }
    if(flag == -1) return ;
    root = new node(mid[flag]);
    t --;
    if(flag < r) build_tree(root->r, t, flag + 1, r);
    if(flag > l) build_tree(root->l, t, l, flag - 1);
}

void build_tree2(node *&root, int &t, int l, int r)   //先序中序求后序
{
    int flag = -1;
    for(int i = l;i <= r;i ++)
    {
        if(pre[t] == mid[i])
        {
            flag = i;break;
        }
    }
    if(flag == -1) return ;
    root = new node(mid[flag]);
    t ++;
    if(flag > l) build_tree2(root->l, t, l, flag - 1);
    if(flag < r) build_tree2(root->r, t, flag + 1, r);
}

void pre_order(node *root)
{
    if(root == NULL) return ;
    printf("%c", root->val);
    if(root->l != NULL) pre_order(root->l);
    if(root->r != NULL) pre_order(root->r);
}

void post_order(node *root)
{
    if(root == NULL) return ;
    if(root->l != NULL) post_order(root->l);
    if(root->r != NULL) post_order(root->r);
    printf("%c", root->val);
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s", pre + 1, mid + 1);
    node *root = NULL;
    int t = 1;
    build_tree2(root, t, 1, n);
    post_order(root);
    system("pause");
    return 0;
}