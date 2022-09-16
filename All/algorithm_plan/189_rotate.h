//
// Created by 17634 on 2022/9/15.
//

#ifndef ALGORITHM_189_ROTATE_H
#define ALGORITHM_189_ROTATE_H

#include <vector>
#include "../../gcd.h"
using namespace std;

//189. 轮转数组
//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

/*此题三种解法：
(1)使用额外的数组: 时间O(n), 空间O(n)
    将数组下标为 ii 的元素放至新数组下标为 (i+k) % n 的位置

(2)环状替换: 时间O(n), 空间O(1)
    设回到原来位置刚好走过 a 圈；再设该过程总共遍历了 b 个元素，则 an = bk;
    an是n、k的最小公倍数，故 b = lcm(n, k) / k; 故遍历次数为n / b = gcd(n, k)

原始数组                         1 2 3 4 5 6 7
翻转所有元素                      7 6 5 4 3 2 1
翻转[0, k % n - 1]区间的元素      5 6 7 4 3 2 1
翻转[k % n, n - 1]区间的元素      5 6 7 1 2 3 4


*/

void rotate(vector<int>& nums, int k) { //法一：使用额外的数组
    vector<int> V(nums);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        nums[(i + k) % n] = V[i];
    }
}

void rotate2(vector<int>& nums, int k) { //法二：环状替换
    int n = nums.size();
    k = k % n;
    int count = gcd(n, k);
    for (int i = 0; i < count; i++) {
        int x = i;
        do {
            x = (x + k) % n;
            swap(nums[i], nums[x]);
        } while (x != i);
    }
}

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start++], nums[end--]);
    }
}

void rotate3(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

#endif //ALGORITHM_189_ROTATE_H
