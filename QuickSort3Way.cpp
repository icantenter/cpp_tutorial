#include <iostream>
#include <cassert>
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

void QuickSort3Way(int a[], int low, int high)
{

    if (low >= high)
        return;
    int lt = low;
    int i = low + 1;
    int gt = high;

    while (i <= gt)
    {
        if (a[i] < a[lt])
        {
            std::swap(a[i], a[lt]);
            i++;
            lt++;
        }
        else if (a[i] > a[lt])
        {
            std::swap(a[i], a[gt]); //这里不能使用i--，因为交换a[gt]和a[i]后，现在的a[i]并没有确定位置，
            gt--;                   //如果使用i++,就将跳过交换后该元素的排序
        }
        else
        {
            i++;
        }
    }
    QuickSort3Way(a, low, lt - 1);
    QuickSort3Way(a, gt + 1, high);
}

int main()
{
    int nums[] = {1, 2, 23, 21, 6, 123, 6, 13, 6, 13, 6, 4, 6, 346, 7, 4, 6, 43, 7, 67, 8};

    QuickSort3Way(nums, 0, sizeof(nums) / sizeof(int) - 1);
    assert(is_sorted(nums, sizeof(nums) / sizeof(int)));
    for (size_t i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        std::cout << nums[i] << ' ';
    }
    
    return 0;
}