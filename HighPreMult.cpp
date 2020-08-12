#include <iostream>
#include <string>
#include <cstring>

void to_Int(std::string &_string, int num[]);
void mul(int a[], int b[], int product[]);
int main()
{
    int num_a[10000], num_b[10000];
    int product[10000];
    std::string a, b;
    //getline有时候会有点问题
    std::cin >> a >> b;
    memset(num_a, 0, sizeof(num_a));
    memset(num_b, 0, sizeof(num_b));
    memset(product, 0, sizeof(product));
    to_Int(a, num_a);
    to_Int(b, num_b);
    mul(num_a, num_b, product);

    for (int i = product[0]; i >= 1; i--)
    {
        std::cout << product[i];
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

void mul(int a[], int b[], int product[])
{
    int i, j;
    for (i = 1; i <= a[0]; i++)
    {
        int offset = 0;
        for (j = 1; j <= b[0]; j++)
        {
            product[i + j - 1] += a[i] * b[j] + offset;
            offset = product[i + j - 1] / 10;
            product[i + j - 1] %= 10;
        }
        //加上最后的offset
        product[i + j - 1] += offset;
    }
    //trim
    int temp_index = i + j - 1;
    while (product[temp_index] == 0 && temp_index > 1)
    {
        temp_index--;
    }
    product[0] = temp_index;
}

