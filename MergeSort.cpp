//看不懂c++的为什么不试试python
//迭代实现

#include <iostream>
#include <cmath>
template <typename Comparable> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
// void merge_sort(Comparable arr[], int len)
// {
//     Comparable *a = arr;
//     Comparable *b = new Comparable[len];
//     //delta是分组的间隔
//     for (int delta = 1; delta < len; delta *= 2)
//     {
//         //start < len 可以访问到每一个数
//         for (int start = 0; start < len; start += delta + delta)
//         {
//             //std::min确保不会越界
//             int low = start, mid = std::min(start + delta, len), high = std::min(start + delta + delta, len);
//             int k = low;
//             int start1 = low, end1 = mid;
//             int start2 = mid, end2 = high;
//             //把两组中小的数放进去辅助数组，并移动pointer或index
//             while (start1 < end1 && start2 < end2)
//                 b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
//             //将i, j中没有到达分组末尾的那组剩余数全部存入temp
//             //下面两个while循环，只会有一个起作用
//             while (start1 < end1)
//                 b[k++] = a[start1++];
//             while (start2 < end2)
//                 b[k++] = a[start2++];
//         }
//         //交换后，b再次成为辅助数组
//         Comparable *temp = a;
//         a = b;
//         b = temp;
//     }
//     //目前次判断的意义
//     if (a != arr)
//     {
//         for (int i = 0; i < len; i++)
//             b[i] = a[i];
//         b = a;
//     }
//     delete[] b;
// }



int main(int argc, char *argv[])
{
    int a[8] = {50, 10, 3, 40, 70, 40, 123, 60};
    merge_sort(a, 8);
    for (int i = 0; i < 8; i++)
        std::cout << a[i] << ' ';
    return 0;
}

void Merge(int r[], int r1[], int s, int m, int t)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])
            r1[k++] = r[i++];
        else
            r1[k++] = r[j++];
    }
    if (i <= m)
        while (i <= m)
            r1[k++] = r[i++];
    else
        while (j <= t)
            r1[k++] = r[j++];
    for (int n = s; n <= t; n++)
        r[n] = r1[n];
}
 
void MergeSort(int r[], int r1[], int s, int t)
{
    if (s < t)
    {
        int m = (s + t) / 2;
        MergeSort(r, r1, s, m);
        MergeSort(r, r1, m + 1, t);
        Merge(r, r1, s, m, t);
    }
}



