//
// Created by 王锐 on 2022/9/16.
//

#ifndef ALGORITHM_907_SUMSUBARRAYMINS_H
#define ALGORITHM_907_SUMSUBARRAYMINS_H

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/*
 907. 子数组的最小值之和
给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。

由于答案可能很大，因此 返回答案模 10^9 + 7 。

示例 1：

输入：arr = [3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
 * */

int get(vector<int>& arr, int i, int n) {
    if (i == -1 || i == n) return INT_MIN;
    return arr[i];
}

int sumSubarrayMins2(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    const int MOD = 1000000007;
    stack<int> S; //辅助栈
    long long ans = 0; //最终结果

    for (int i = -1; i <= n; i++) {
        while (!S.empty() && get(arr, S.top(), n) > get(arr, i, n)) {
            int cur = S.top(); S.pop();
            ans = (ans + (long long)(cur - S.top()) * (i - cur) * arr[cur]) % MOD;
        }
        S.push(i);
    }
    return int(ans);
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    const int MOD = 1000000007;
    stack<int> S;

    int left[n]; //每个元素辐射的左边界
    //第一次遍历找到所有元素的左边界
    for (int i = 0; i < n; i++) { //以i为基点找<arr[i]的左边界
        while (!S.empty() && arr[S.top()] > arr[i])
            S.pop();
        left[i] = S.empty() ? -1 : S.top();
        S.push(i);
    }
    while (!S.empty()) S.pop(); //清空栈

    int right[n]; //每个元素辐射的左边界
    //第二次遍历找到所有元素的右边界
    for (int i = n - 1; i > -1; i--) {
        while (!S.empty() && arr[S.top()] >= arr[i])
            S.pop();
        right[i] = S.empty() ? n : S.top();
        S.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)(i - left[i]) * (right[i] - i) * arr[i]) % MOD;
    }
    return int(ans);
}

/*此方法总结:
 *注意⚠️：在计算左边界或者右边界时将一侧设置为求解小于等于E的元素，目的是为了解决当一个子数组中有两个最小值元素时（比如[3,1,2,4,1]中有两个1），不重复且不遗漏地统计每一个子数组。

 *****左边找的边界值严格<=arr[i]，右边严格<arr[i]
arr        1       1
left[]    -1      0
right[]   2       2
 故： 1 * (0 - -1) * (2 - 0) + 1 * (1 - 0) * (2 - 1) = 3
 即： 第一个位置取[1], [1, 1]，第二个位置只取[1]

*/

void testSumSubarrayMins() {
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins2(arr) << endl;
}

#endif //ALGORITHM_907_SUMSUBARRAYMINS_H
