//
// Created by 王锐 on 2021/11/28.
//

#ifndef ALGORITHM_POINTER2_H
#define ALGORITHM_POINTER2_H

#include <vector>
#include <iostream>

using namespace std;

//给定正整数组成的数组、k的值，有多少个数字乘积<k的连续子数组？

int numSubArrayProductLessThanK(vector<int> &nums, int k) {
    int count = 0;
    int product = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];
        while (left <= right && product >= k) {
            product /= nums[left++];
        }
        count += right >= left ? right - left + 1 : 0;
    }
    return count;
}

void testNumSubArrayProductLessThanK() {
    int A[] = {10, 5, 2, 6};
    vector<int> nums(A, A + sizeof(A) / sizeof(int));

    int res = numSubArrayProductLessThanK(nums, 100);
    cout << res << endl;
}

#endif //ALGORITHM_POINTER2_H
