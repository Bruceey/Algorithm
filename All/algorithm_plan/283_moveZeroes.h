//
// Created by 王锐 on 2022/9/16.
//

#ifndef ALGORITHM_283_MOVEZEROES_H
#define ALGORITHM_283_MOVEZEROES_H

#include <vector>
#include <iostream>
using namespace std;

/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
*/

void moveZeroes(vector<int>& nums) {
    int left = 0, right = 0;
    int n = nums.size();
    while (right < n) { //遍历一次，出现0成"块"的现象，left永远指向"块"左边第一个0
        if (nums[right]) //一旦发现非0，立刻与left处值交换，并且left指向下一个0
            swap(nums[left++], nums[right]);
        right++;
    } //注意刚开始可能left和right都非0，此时原地交换
}

//测试代码
void moveZeroesTest() {
    vector<int> nums = {0,1,0,3,12};
    cout << "原数组：";
    for (auto & x : nums) cout << x << " ";
    cout << endl;
    moveZeroes(nums);
    cout << "现数组：";
    for (auto & x : nums) cout << x << " ";
    cout << endl;
}

#endif //ALGORITHM_283_MOVEZEROES_H
