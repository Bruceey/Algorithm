//
// Created by 17634 on 2022/9/14.
//

#ifndef ALGORITHM_1619_TRIMMEAN_H
#define ALGORITHM_1619_TRIMMEAN_H

//1619. 删除某些元素后的数组均值
//给你一个整数数组 arr ，请你删除最小 5% 的数字和最大 5% 的数字后，剩余数字的平均值。
//
//与 标准答案 误差在 10-5 的结果都被视为正确结果。

#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int lo, int hi) {  //范围是[lo, hi)
    swap(arr[lo], arr[lo + rand() % (hi - lo)]); //防止退化情况发生，即原数组已经是倒序排列
    int pivot = arr[lo]; //轴点
    int mi = lo; //初始化分界点mi
    for (int k = lo + 1; k < hi; k++)
        if (arr[k] < pivot)  //将比轴点pivot小的值全部移到左边，即
            swap(arr[++mi], arr[k]); //等同于将分界点mi向右移
    swap(arr[lo], arr[mi]); //for循环后mi处的值即为最后一个比轴点pivot小的值，将其值与轴点交换
    return mi; //返回分界点，此时mi处左边的值全部 < arr[mi], 右边全部 >= arr[mi]
}

void quickSort(vector<int>& arr, int lo, int hi) { //范围是[lo, hi)
    if (hi - lo < 2) return; //单个值自然有序
    int mi = partition(arr, lo, hi); //得到分界点
    quickSort(arr, lo, mi); //分界点左边快排
    quickSort(arr, mi + 1, hi); //分界点右边快排
}

double trimMean(vector<int>& arr) {
    int len = arr.size();
    quickSort(arr, 0, len); //快排
    int lo = int(len * 0.05);
    int hi = len - lo;
    int n = hi - lo;
    double sum_ = 0.;
    while (lo < hi)
        sum_ += arr[lo++];
    return sum_ / n;
}

#endif //ALGORITHM_1619_TRIMMEAN_H
