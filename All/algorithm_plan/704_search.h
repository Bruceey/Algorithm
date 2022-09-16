//
// Created by 17634 on 2022/9/14.
//

#ifndef ALGORITHM_704_SEARCH_H
#define ALGORITHM_704_SEARCH_H

#include <vector>
using namespace std;

//704. 二分查找
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1

int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size();
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (target == nums[mi]) return mi;
        else if (target < nums[mi]) hi = mi;
        else lo = mi + 1;
    }
    return -1;
}

#endif //ALGORITHM_704_SEARCH_H
