#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <vector>

#define DeaultLength 100

class BinaryHeap
{
    public:
        BinaryHeap(int len = DeaultLength);
        BinaryHeap(const std::vector<int> & item);

        ~BinaryHeap();

        bool isEmpty() const;
        int findMin() const;

        bool isFull();
        void insert(int x);
        bool deleteMin();
        bool makeEmpty();

    private:
        /**
         * 二叉堆内部方法 完成下滤
         * params: location : 下滤的位置
         * 当 location<=0 时, 直接将location置为1, 默认从根节点开始进行下滤
         * 在进行下滤时, 需要考虑该节点不能是叶子节点, 且当该节点只有一个孩子时的情况
         */
        void percolateDown(int location = 1);

    private:
        int currentSize = 0;                        // 堆中元素的个数
        int maxLength = DeaultLength;               // 数组的最大长度
        int * array = nullptr;                      // 实现堆得数组
};

#endif
