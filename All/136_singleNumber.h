//
// Created by 王锐 on 2022/9/18.
//

#ifndef ALGORITHM_136_SINGLENUMBER_H
#define ALGORITHM_136_SINGLENUMBER_H

#include <vector>
#include <iostream>

using namespace std;

/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
 * */

int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (auto& x : nums) ret ^= x;
    return ret;
}

void testSingleNumber() {
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums);
}

#endif //ALGORITHM_136_SINGLENUMBER_H
