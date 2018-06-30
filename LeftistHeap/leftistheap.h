#ifndef LEFTIST_H_
#define LEFTIST_H_

struct Node
{
    Node *lelfChild;
    Node *righChild;
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
 * 和Merge共同通过递归完成两个堆得合并
 * params: one_heap, other_heap分别为两个不同的左式堆
 * return: 返回一个左式堆
 */
Node * innerMerge(Node * one_heap, Node * other_heap);

/**
 * 合并两个左式堆
 * params: one_heap, other_heap分别为两个不同的左式堆
 * return: 返回一个左式堆，如果无法合并返回NULL
 */
Node * Merge(Node * one_heap, Node other_heap);

/**
 * 获取value最小的一个节点
 * 由左式堆的性质可得根节点的value就是最小的，当获取到该节点后将该节点移出该堆，这时左右子堆就形成了两个独立的左式堆
 * 将这两个左式堆进行合并就可以得到移出后的新堆
 * params: root_node: 根节点
 * return: 返回新生成的堆
 */
Node * RemoveMinNode(Node * root_node);

#endif
