#include <iostream>
void fun1();
void fun3();
void fun2();
int main()
{
    void (*p[])() = {fun1, fun2, fun3};
    for (int i = 0; i < sizeof(p); i++) 
    {
        p[i]();
    }
    return 0;
}

void fun1()
{
    std::cout << 1 << std::endl;
}

void fun2()
{
    std::cout << 2 << std::endl;
}

void fun3()
{
    std::cout << 3 << std::endl;
}