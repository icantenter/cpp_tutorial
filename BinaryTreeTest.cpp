#include "BinaryTree.h"
//#define aoligei

#ifndef aoligei
#define c 3
#endif

int main()
{
    int key = c;
    auto st = new BinaryTree<int, int>();
    for (int i = 0; i < 4; i++)
    {
        std::cin >>  key;
        st->put(key, i );
    }
    
    return 0;
}

