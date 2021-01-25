#include <bits/stdc++.h>
using namespace std;
#define FALSE 0
#define TRUE 1
#define Status int

struct node
{
    int value;
    node *next;
};

typedef struct Hash
{
    node *hash[10];
}Hash,* HashTable;

void initHashTable(HashTable &table)
{
    table = (HashTable)malloc(sizeof(Hash));
}

Status Insert_val(HashTable &table, int value)
{
    if (table == NULL)
        return FALSE;
    int val = value % 10;
    node *p = table->hash[val];
   
    while (p->next != NULL)
    {
        p = p->next;
    }
    node *s = (node *)malloc(sizeof(node));
    s->next = NULL;
    s->value = value;
    p->next = s;
    return TRUE;
}

Status Delete(HashTable &table, int value)
{
    int val = value % 10;
    if (table == NULL || table->hash[val] == NULL)
        return FALSE;
    node *p = table->hash[val];
    node *pre, *s;
    if(p->next->value == value)
    {
        s = p->next;
        p = p->next->next;
        free(s);
        return TRUE;
    }
    int flag = 0;
    while (p->next != NULL)
    {
        if (p->value == value)
        {
            flag = 1;
            s = p;
            pre->next = p->next;
            break;
        }
        pre = p;
        p = p->next;
    }
    free(s);
    if(flag == 1) return TRUE;
    else return FALSE;
}

void Print_Hash(HashTable table)
{
    for(int i = 0;i <= 9;i ++){
        node *p = table->hash[i]->next;
        if(p == NULL) printf("%d ----------- NULL", i);
        else printf("%d -----------", i);
        while(p != NULL)
        {
            printf(" %d", p->value);
            p = p->next;
        }
        printf("\n\n");
    }
}

int main()
{
    HashTable table;
    initHashTable(table);
    for(int i = 0;i < 10;i ++){
        table->hash[i] = (node *) malloc(sizeof(node));
        table->hash[i]->next = NULL;
    }
    Insert_val(table, 1);
    Insert_val(table, 11);
    Insert_val(table, 13);
    Insert_val(table, 15);
    Insert_val(table, 89);
    Print_Hash(table);
    system("pause");
    return 0;
}