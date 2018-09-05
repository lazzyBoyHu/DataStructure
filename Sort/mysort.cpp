#include <iostream>

#include "mysort.h"


InsertionSort::InsertionSort()
{
}

void InsertionSort::sort()
{
    for(int i = 1; i < length; i++)
    {
        int tmp = std::move(arr[i]);
        int j = 0;
        for(j = i-1; j >= 0 && tmp < arr[i]; j++)
            arr[j + 1] = std::move(arr[j]);
        arr[j] = std::move(tmp);
    }
}
