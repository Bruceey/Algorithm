//
// Created by 王锐 on 2021/11/28.
//

#ifndef ALGORITHM_NUMSUBARRAYSUMISK_H
#define ALGORITHM_NUMSUBARRAYSUMISK_H
#include <vector>
#include <iostream>
using namespace std;

int numSubArraySumIsK(vector<int>& nums, int k) {
    //nums中都是正整数
    int count = 0;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (left <= right && sum > k) {
            sum -= nums[left++];
            if (sum == k) count++;
        }
    }
    return count;
}


#endif //ALGORITHM_NUMSUBARRAYSUMISK_H
