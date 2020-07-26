#include <iostream>
#include <cassert>
template <typename Comparable>
void show(Comparable array[], int size)
{

    if (size == 0)
    {
        return;
    }
    system("cls");
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j] >= i)
            {
                std::cout << "■";
            }
            else
            {
                std::cout << "  ";
            }
            if (j == size - 1)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << "  ";
            }
        }
    }
    system("pause");
}

template <typename Comparable>
bool is_sorted(Comparable array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;

    std::cin >> num;
    auto *nums = new int[num];

    for (int i = 0; i < num; i++)
    {
        std::cin >> nums[i];
    }

    for (int i = 1; i < num; i++)
    {
        int preindex = i - 1;
        int insertion = nums[i]; //排序过程中nums[i]会变
        while (nums[preindex] > insertion && preindex >= 0)
        {
            nums[preindex + 1] = nums[preindex];
#define debugging
#ifdef debugging
            show(nums, num);
#endif
            preindex--;
        }
        //preindex代表前面的数,可以为0
        //前面的数<=insertion, preindex + 1的数也移走了，就可以插入了
        nums[preindex + 1] = insertion;
#define debugging
#ifdef debugging
        show(nums, num);
#endif
    }
    assert(is_sorted(nums, num));
    for (int i = 0; i < num; i++)
    {
        std::cout << nums[i] << ' ';
    }

    return 0;
}