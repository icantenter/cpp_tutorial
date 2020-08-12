#include <iostream>
#include <string>
#include <cstring>
void to_Int(std::string &_string, int num[]);
void add(int a[], int b[], int sum[]);

int main()
{
    int num_a[10000], num_b[10000];
    int sum[10000];
    std::string a, b;
    //getline有时候会有点问题
    std::cin >> a >> b;
    memset(num_a, 0, sizeof(num_a));
    memset(num_b, 0, sizeof(num_b));
    memset(sum, 0, sizeof(sum));
    to_Int(a, num_a);
    to_Int(b, num_b);
    add(num_a, num_b, sum);

    for (int i = sum[0]; i >= 1; i--)
    {
        std::cout << sum[i];
    }

    return 0;
}

void to_Int(std::string &_string, int num[])
{
    num[0] = _string.length();
    for (int i = 1; i <= _string.length(); i++)
    {
        num[i] = _string[num[0] - i] - '0';
    }
}

int _max(int a, int b)
{
    return a > b ? a : b;
}

void add(int a[], int b[], int sum[])
{
    int i;
    //考虑最后的offset, 所以_max(a[0], b[0]) + 1要加1
    for (i = 1; i <= _max(a[0], b[0]) + 1; i++)
    {
        sum[i] = a[i] + b[i];
        if (sum[i] >= 10)
        {
            sum[i] -= 10;
            a[i + 1]++;
        }
    }
    //trim
    while (sum[i] == 0 && i > 1)
    {
        i--;
    }
    sum[0] = i;
}

