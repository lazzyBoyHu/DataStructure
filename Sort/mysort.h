#ifndef MYSORT_H_
#define MYSORT_H_

#define DefaultLength 20

#include <iostream>
#include <stdlib.h>

/**
 * 定义一个排序的基类
 * 两个成员变量: arr: 数组; length: 数组的长度;
 */
class BaseSort
{
    public:
        int * arr = nullptr;    // 声明一个空的指针用于保存数组元素
        int length;             // 数组的长度
    public:
        /**
         * 两个构造函数
         * 无参构造函数, 定义一个默认长度的数组
         * 有参构造函数, 参数为数组的长度, 当参数小雨或者等于0时, 生成一个默认长度的数组
         */
        BaseSort()
        {
            arr = (int*)malloc(sizeof(int *) * DefaultLength);
            length = DefaultLength;
        }
        BaseSort(int len)
        {
            if (len <= 0)
                len = DefaultLength;
            arr = (int *)malloc(sizeof(int *) * len);
            length = len;
        }
        // 析构函数
        ~BaseSort()
        {
            free(arr);
        }

        /**
         * 读入数据
         * 循环读入数据, 如果读入的数据不足, 则realloc申请到的内存
         */
        void readData()
        {
            int index = 0;
            while(std::cin.peek() != EOF && std::cin.peek() != '\n')
            {
                std::cin >> arr[index++];
                if (index == length)
                    break;
            }
            if (index < length)
            {
                arr = (int *)realloc(arr, sizeof(int *) * index);
                length = index;
            }
            for (int i = 0; i < index; i++)
                std::cout << i << ": " << arr[i] << std::endl;
        }
        /**
         * 通过一个已有的数组初始化要排序的数组
         * params: array: 数组; len: 长度
         */
        bool setArray(int * array, int len)
        {
            if (len > 0 && array != nullptr)
            {
                arr = array;
                length = len;
                return true;
            }
            return false;
        }
        /**
         * 打印数据
         */
        void printArr()
        {
            for(int i = 0; i < length; i++)
                std::cout << "第" << i + 1 << "个数据为: " << arr[i] << "; " << std::endl;
        }
        /**
         * 排序的实现
         */
        virtual void sort();
};

class BubbleSort : BaseSort
{
    public:
        BubbleSort();
        void sort();
};

class InsertionSort : BaseSort
{
    public:
        InsertionSort();
        void sort();
};

class ShellSort : BaseSort
{
    public:
        ShellSort();
        void sort();
};

#endif
