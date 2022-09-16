//
// Created by 王锐 on 2021/11/29.
//

#ifndef ALGORITHM_SUBARRAYSUM_H
#define ALGORITHM_SUBARRAYSUM_H

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
int subArraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x: nums) {
        pre += x;
        if (mp.find(pre - k) != mp.end())
            count += mp[pre - k];
        mp[pre]++;
    }
    return count;
}

void subArraySumTest() {
//    int A[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int A[] = {1, 2, 3};
    int k = 3;
    vector<int> nums(A, A + sizeof(A) / sizeof(int));
    int res = subArraySum(nums, k);
    cout << res << endl;
}


#endif //ALGORITHM_SUBARRAYSUM_H
