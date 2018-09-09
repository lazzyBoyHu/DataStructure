#ifndef MYSORT_H_
#define MYSORT_H_

#define DefaultLength 20

#include <iostream>
#include <stdlib.h>

#define random(x) (rand()%x)

/**
 * 定义一个排序的基类
 * 两个成员变量: arr: 数组; length: 数组的长度;
 */
class BaseSort
{
    public:
        int * arr;    // 声明一个空的指针用于保存数组元素
        int length;             // 数组的长度
    public:
        /**
         * 两个构造函数
         * 无参构造函数, 定义一个默认长度的数组
         * 有参构造函数, 参数为数组的长度, 当参数小雨或者等于0时, 生成一个默认长度的数组
         */
        BaseSort();
        BaseSort(int len);
        // 析构函数
        virtual ~BaseSort()
        {
            free(arr);
        }

        /**
         * 读入数据
         * 循环读入数据, 如果读入的数据不足, 则realloc申请到的内存
         */
        void readData();
        /**
         * 通过一个已有的数组初始化要排序的数组
         * params: array: 数组; len: 长度
         */
        bool setArray(int * array, int len);
        /**
         * 随机生成一组数据
         */
        void setRandomData();
        /**
         * 打印数据
         */
        void printArr();
        void printOneLine();
        /**
         * 排序的实现
         */
        virtual void sort() = 0;
};

class BubbleSort : public BaseSort
{
    public:
        BubbleSort();
        void sort();
};

class InsertionSort : public BaseSort
{
    public:
        InsertionSort();
        void sort();
};

class ShellSort : public BaseSort
{
    public:
        ShellSort();
        void sort();
};

#endif
