//
// Created by 17634 on 2022/9/15.
//

#ifndef ALGORITHM_977_SORTEDSQUARES_H
#define ALGORITHM_977_SORTEDSQUARES_H

#include <vector>
using namespace std;

//977. 有序数组的平方
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
//请你设计时间复杂度为 O(n) 的算法解决本问题
//提示：
//1 <= nums.length <= 104
//-104 <= nums[i] <= 104
//nums 已按 非递减顺序 排序

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res(nums.size());
    int k = nums.size() - 1;
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int left_mul = nums[i] * nums[i];
        int right_mul = nums[j] * nums[j];
        if (left_mul < right_mul) {
            res[k--] = right_mul;
            j--;
        } else {
            res[k--] = left_mul;
            i++;
        }
    }
    return res;
}

#endif //ALGORITHM_977_SORTEDSQUARES_H
