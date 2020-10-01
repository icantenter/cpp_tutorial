#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#define SIZE 10
typedef struct IndexString
{
    int index;
    std::string string;
}IndexString;

void sort(IndexString a[], size_t N, size_t size);
int main()
{
    IndexString *a = new IndexString[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        a[i].index = rand() % SIZE + 1;
        a[i].string = 'a' + i;
    }

    sort(a, SIZE, SIZE);
    
    for (int i = 0; i < SIZE; i++) 
    {
        std::cout << a[i].index << ' ' << a[i].string << std::endl;
    }
    

    return 0;
}

void sort(IndexString a[], size_t N, size_t size)
{
    IndexString *aux = new IndexString[N];
    int *count = new int[size + 1];

    memset(count, 0, sizeof(int) * (size + 1));
    for (int i = 0; i < N; i++) 
    {
        count[a[i].index + 1]++;
    }
    for (int i = 0; i < size + 1; i++) 
    {
        count[i + 1] += count[i];
    }
    for (int i = 0; i < N; i++) 
    {
        aux[count[a[i].index]++] = a[i];
    }
    for (int i = 0; i < N; i++) 
    {
        a[i] = aux[i];
    }
    



}