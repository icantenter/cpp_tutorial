#include <iostream>
#include <algorithm>
#include <cstring>

typedef struct BigInteger
{
    int pos[5010];
    int count;
    BigInteger(int num)
    {
        *this = num;
    }

    BigInteger() : count(0) {};

    BigInteger operator= (int num)
    {
        if (num == 0)
        {
            count = 1;
            return *this;
        }
        count = 0;
        while (num)
        {
            pos[count] = num % 10;
            num /= 10;
            count++;
        }
        return *this;
    }

    BigInteger operator+ (BigInteger &b)
    {
        BigInteger digit;
        int offset = 0;
        digit.count = std::max(b.count, count) + 1;
        for (int i = 0; i < digit.count; i++)
        {
            digit.pos[i] = b.pos[i] + this->pos[i] + offset;
            offset = digit.pos[i] / 10;
            digit.pos[i] %= 10;
        }
        if (digit.pos[digit.count - 1] == 0)
            digit.count--;
        return digit;
    }
}BigInteger;

std::ostream& operator<< (std::ostream& stream,const BigInteger &x)
{
    for (int i = x.count - 1; i >= 0; --i)
    {
        std::cout << x.pos[i];
    }
    return stream;
}