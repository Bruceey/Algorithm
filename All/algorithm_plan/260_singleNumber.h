//
// Created by 王锐 on 2022/9/19.
//

#ifndef ALGORITHM_260_SINGLENUMBER_H
#define ALGORITHM_260_SINGLENUMBER_H

#include <vector>
using namespace std;

/*
 260. 只出现一次的数字 III
给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。


示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
 * */

vector<int> singleNumber260_0(vector<int>& nums) {
    int xorsum = 0;
    for (auto & x : nums) xorsum ^= x;
    int lowbit = (xorsum == INT_MIN) ? xorsum : xorsum & -xorsum;
    int type1 = 0; //第一类: 与lowbit位对应的位为1
    int type2 = 0; //第二类: 与lowbit位对应的位为0
    for (auto & x : nums)
        if (x & lowbit) type1 ^= x;
        else type2 ^= x;
    return {type1, type2};
}

vector<int> singleNumber260(vector<int>& nums) {
    int xorsum = 0;
    for (auto & x : nums) xorsum ^= x;
    int lowbit = (xorsum == INT_MIN) ? xorsum : xorsum & -xorsum;
    int type1 = 0; //第一类: 与lowbit位对应的位为1
    for (auto & x : nums)
        if (x & lowbit) type1 ^= x;
    return {type1, xorsum ^ type1};
}

//注意：
// Integer.MIN_VALUE = -2147483648，取负数变成（2147483648）会溢出，而且 Integer.MIN_VALUE 也不需要计算 lowbit，
// 因为它的二进制是 100....00（共32位），lowbit 是它本身

#endif //ALGORITHM_260_SINGLENUMBER_H
