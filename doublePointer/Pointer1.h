//
// Created by 王锐 on 2021/11/27.
//

#ifndef ALGORITHM_POINTER1_H
#define ALGORITHM_POINTER1_H


#include <climits>

// 给定正整数组成的数组、k的值，求解和>=k的最短子数组长度。
int minSubArrayLen(vector<int>& nums, int k) {
    int left = 0;
    int sum = 0;
    int minLength = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (left <= right && sum >= k) {
            minLength = min(minLength, right-left+1);
            sum -= nums[left++];
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}

void minSubArrayLenTest() {
    int nums0[] = {5, 1, 4, 2, 2, 4};
//    int nums0[] = {5};
    vector<int> nums(nums0, nums0+sizeof(nums0)/sizeof(int));
    int minLength = minSubArrayLen(nums, 7);
    cout << minLength;
}

#endif //ALGORITHM_POINTER1_H
