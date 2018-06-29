#include <iostream>

#include "leftistheap.h"

bool Swap(Node * root_node)
{
    if (root_node == nullptr)
        return false;
    Node * temp = nullptr;
    temp = root_node->righChild;
    root_node->righChild = root_node->lelfChild;
    root_node->lelfChild = temp;
    return true;
}

Node * Merge(Node * one_heap, Node * other_heap)
{
    if (one_heap == nullptr && other_heap != nullptr)
        return other_heap;
    if (one_heap != nullptr && other_heap == nullptr)
        return one_heap;
    if (one_heap->value < other_heap->value)
        one_heap = innerMerge(one_heap, other_heap);
    else
        one_heap = innerMerge(other_heap, one_heap);
    return one_heap;
}

Node * innerMerge(Node * one_heap, Node * other_heap)
{
    if (one_heap->lelfChild == nullptr)
        one_heap->lelfChild = other_heap;
    else
    {
        one_heap->righChild = Merge(one_heap->righChild, other_heap);
        if (one_heap->lelfChild->distance < one_heap->righChild->distance)
            Swap(one_heap);
        one_heap->distance = one_heap->righChild->distance + 1;
    }
    return one_heap;
}
