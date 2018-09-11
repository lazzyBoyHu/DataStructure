#include <iostream>

#include "BinaryHeap.h"


BinaryHeap::BinaryHeap(int len)
{
    if(len < 0)
        len = DeaultLength;
    maxLength = len;
    array = new int[maxLength];
}

BinaryHeap::BinaryHeap(const std::vector<int> & item)
{
    if(item.empty())
        BinaryHeap();
    else
    {
        array = new int[item.size() + 1];
        for(unsigned i = 0; i < item.size(); i++)
            array[i+1] = item[i];
    }
}

BinaryHeap::~BinaryHeap()
{
    delete [] array;
}

bool BinaryHeap::isEmpty() const
{
    if(maxLength == 0)
        return true;
    return false;
}

int BinaryHeap::findMin() const
{
    if (array != nullptr)
        return array[1];
    return 0;
}

bool BinaryHeap::isFull()
{
    if(currentSize == maxLength)
        return false;
    return true;
}

void BinaryHeap::insert(int x)
{
    if(isFull())
    {
        int hole;
        for (hole = ++currentSize; array[hole / 2] > x; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = x;
    }
}

bool BinaryHeap::makeEmpty()
{
    currentSize = 0;
    delete [] array;
    array = new int[maxLength];
    return true;
}

bool BinaryHeap::deleteMin()
{
    if(isEmpty())
    {
        std::cout << "删除一个元素出错  堆为空";
        return false;
    }
    else
    {
        percolateDown(1);
        return true;
    }
}

void BinaryHeap::percolateDown(int location)
{
    if(location <= 0)
        location = 1;
    int tmp = array[currentSize--];
    int hole = location;
    int child;
    for(; hole *2 <= currentSize; hole = child)
    {
        child = hole *2;
        if(child != currentSize && array[child + 1] < array[child])
            child++;
        if(array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}
