#include <iostream>

#include "mysort.h"

using std::move;

//     -------------------   冒泡排序   ------------------
BubbleSort::BubbleSort()
{
}
void BubbleSort::sort()
{
    for(int i = 0; i < length; i++)
        for(int j = 0; j < length - i; j++)
            if(arr[j] > arr[j+1])
            {
                int tmp = move(arr[j+1]);
                arr[j+1] = move(arr[j]);
                arr[j] = move(tmp);
            }
}
//     -------------------   冒泡排序   ------------------


//     -------------------   插入排序   ------------------
InsertionSort::InsertionSort()
{
}

void InsertionSort::sort()
{
    for(int i = 1; i < length; i++)
    {
        int tmp = move(arr[i]);
        int j = 0;
        for(j = i-1; j >= 0 && tmp < arr[i]; j++)
            arr[j + 1] = move(arr[j]);
        arr[j] = move(tmp);
    }
}
//     -------------------   插入排序   ------------------
