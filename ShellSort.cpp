#include <iostream>
#include <cassert>

template <typename Comparable>
bool is_sorted(Comparable array[], int size);

template <typename _RIter>
void shell_sort(_RIter st, _RIter ed);

int num;
int *nums;

int main()
{

    std::cin >> num;
    nums = new int[num];

    for (int i = 0; i < num; i++)
    {
        std::cin >> nums[i];
    }
    shell_sort(nums, nums + num);
    assert(is_sorted(nums, num));
    for (int i = 0; i < num; i++)
    {
        std::cout << nums[i] << ' ';
    }
    return 0;
}

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

template <typename _Iter>
void show(_Iter start , _Iter end)
{

    if (start >= end)
    {
        return;
    }
    system("cls");
    _Iter max = start;
    for (_Iter i = start + 1; i < end; i++)
    {
        if (*i > *max)
        {
            max = i;
        }
    }
    for (int i = *max; i > 0; i--)
    {
        //j取不到end, j < end , != end
        for (_Iter j = start; j < end ; j++)
        {
            if (*j >= i)
            {
                std::cout << "■";
            }
            else
            {
                std::cout << "  ";
            }
            if (j == end - 1)
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

//模板使用了指针，定义key就很麻烦。所以用swap，性能有影响
template <typename _RIter>
void insert_sort(_RIter st, _RIter ed, int delta)
{
    for (_RIter i = st + delta; i < ed; i += delta)
    {
        _RIter j = i;
        while (*j < *(j - delta) && j > st)
        {
            std::swap(*j, *(j - delta));
#define debugging
#ifdef debugging
            show(nums, num);
#endif
            j -= delta;
        }
    }
}

template <typename _RIter>
void shell_sort(_RIter st, _RIter ed)
{
    //大循环更新delta(delta指数学上的△)
    for (int delta = ed - st; delta; delta /= 2)
        //delta为多少,分多少组
        for (int i = 0; i < delta; i++)
            insert_sort(st + i, ed, delta);
}