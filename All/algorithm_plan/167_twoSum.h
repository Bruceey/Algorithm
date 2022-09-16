//
// Created by 王锐 on 2022/9/16.
//

#ifndef ALGORITHM_167_TWOSUM_H
#define ALGORITHM_167_TWOSUM_H

#include <vector>
using namespace std;

/*
 167. 两数之和 II - 输入有序数组
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
 * */

vector<int> twoSum167_2(vector<int>& numbers, int target) { //双指针、贪婪
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        if (numbers[left] + numbers[right] == target)
            return {left + 1, right + 1};
        else if (numbers[left] + numbers[right] < target)
            left++;
        else
            right--;
    }
    return {-1, -1};
}


vector<int> twoSum167(vector<int>& numbers, int target) { //二分查找
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (target - numbers[i] == numbers[mi])
                return {i + 1, mi + 1};
            else if (target - numbers[i] < numbers[mi])
                hi = mi - 1;
            else
                lo = mi + 1;
        }
    }
    return {-1, -1};
}

#endif //ALGORITHM_167_TWOSUM_H
