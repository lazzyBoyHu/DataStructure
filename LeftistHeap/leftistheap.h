#ifndef LEFTIST_H_
#define LEFTIST_H_

struct Node
{
    Node *lelfChild;
    Node *righChild;
    Node *parents;
    int distance;
    int value;
};

/**
 * 交换左右子树
 * params: root_node : 需要交换左右子树的节点
 * return: 如果节点存在，交换子树，返回true；如果不存在，返回false
 */
bool Swap(Node * root_node);

/**
 * 合并的内部方法
 * params: one_heap, other_heap分别为两个不同的左式堆
 * return: 返回一个左式堆，如果无法合并返回NULL
 */
Node * innerMerge(Node * one_heap, Node * other_heap);

/**
 * 合并两个左式堆
 * params: one_heap, other_heap分别为两个不同的左式堆
 * return: 返回一个左式堆，如果无法合并返回NULL
 */
Node * Merge(Node * one_heap, Node other_heap);

#endif
