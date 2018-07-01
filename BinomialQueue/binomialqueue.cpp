#include <iostream>
#include <stdlib.h>

#include "binomialqueue.h"

// 定义一个二项队列, 默认长度为MaxLength
Node * binomialQueue = (Node *)malloc(MaxLength * sizeof(Node *));

Node * initBinomialQueue(int length)
{
    if (length != MaxLength)
        binomialQueue = (Node *)realloc(binomialQueue, sizeof(Node) * length);
    return binomialQueue;
}

Node * merge(Node * one_queue, Node * other_queue, int length)
{
    Node tempQueue[length];
    for (int index = 0; index < length; index++)
    {
        if (&one_queue[index] == nullptr && &other_queue[index] == nullptr && &tempQueue[index] == nullptr)
            continue;
        else if (&one_queue[index] == nullptr && &other_queue[index] == nullptr && &tempQueue[index] != nullptr)
            one_queue[index] = tempQueue[index];
        else if (&one_queue[index] == nullptr && &tempQueue[index] == nullptr && &other_queue[index] != nullptr)
            one_queue[index] = other_queue[index];
        else if (&other_queue[index] == nullptr && &tempQueue[index] == nullptr && &one_queue[index] != nullptr)
            one_queue[index] = one_queue[index];
        else if (&tempQueue[index] == nullptr)
        {
            if (one_queue[index].value < other_queue[index].value)
                one_queue[index].allChild.push_back(other_queue[index]);
            else
            {
                other_queue[index].allChild.push_back(one_queue[index]);
                one_queue[index] = other_queue[index];
            }
        }
        else
        {
            Node tempNodes[3] = {one_queue[index], other_queue[index], tempQueue[index]};
            for (int i = 0; i < 3; i++)
                for (int j = i + 1; j < 3; j++)
                    if (tempNodes[i].value > tempNodes[j].value)
                    {
                        Node tempNode = tempNodes[i];
                        tempNodes[i] = tempNodes[j];
                        tempNodes[j] = tempNodes[i];
                    }
            tempNodes[0].allChild.push_back(tempNodes[1]);
            tempQueue[index + 1] = tempNodes[0];
            one_queue[index] = tempNodes[2];
        }
    }
    return one_queue;
}
