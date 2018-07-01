#ifndef BINOMIALQUEUE_H_
#define BINOMIALQUEUE_H_

#define MaxLength 10

#include <vector>

// 定义二项队列中的节点
struct Node
{
    std::vector<Node> allChild;     // 相比于数组, 用vector更容易操作
    int value;
};

/**
 * 初始化一个二项队列默认长度是10
 * params: length: 长度默认值为10
 * return: 返回一个Node数组
 */
Node * initBinomialQueue(int length = MaxLength);

/**
 * 合并两个队列
 * params: one_queue, other_queue 分别为两个二项队列
 * return: 返回合并之后的二项队列
 */
Node * merge(Node * one_queue, Node * other_queue, int length);

/**
 * 删除最小的节点
 * 通过遍历整个数组, 找到最小的节点, 移除该节点，并将其子树依次合并到移除这一支后的树中
 * params: queue: 需要移除最小元的二项队列
 */
void deleteMinNode(Node * queue);

#endif
