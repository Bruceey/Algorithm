//
// Created by 王锐 on 2021/12/5.
//

#ifndef ALGORITHM_TRAP_H
#define ALGORITHM_TRAP_H

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//42. 接雨水
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//方法一：单调递减栈
int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    stack<int> stk;
    int inflow = 0;

    for (int i = 0; i < height.size(); i++) {
        while (!stk.empty() && height[stk.top()] < height[i]) {
            int h0 = height[stk.top()]; stk.pop();
            if (stk.empty()) break;

            int h = min(height[stk.top()], height[i]) - h0;
            int w = i - stk.top() - 1;
            inflow += w * h;
        }
        stk.push(i);
    }
    return inflow;
}

//方法二：动态规划
int trap2(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;
    int leftMax[n], rightMax[n];
    leftMax[0] = height[0]; rightMax[n-1] = height[n-1];
    for (int i = 1; i < n; i++) {
        if (leftMax[i-1] < height[i]) leftMax[i] = height[i];
        else leftMax[i] = leftMax[i-1];
    }
    for (int j = n - 2; j >= 0; j--) {
        if (rightMax[j+1] < height[j]) rightMax[j] = height[j];
        else rightMax[j] = rightMax[j+1];
    }

    int inflow = 0;
    for (int i = 0; i < n; i++) {
        inflow += min(leftMax[i], rightMax[i]) - height[i];
    }
    return inflow;
}

//方法三：双指针
int trap3(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int inflow = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (height[left] < height[right]) {
            inflow += leftMax - height[left];
            left++;
        } else {
            inflow += rightMax - height[right];
            right--;
        }
    }
    return inflow;
}

//利用C语言写的双指针
int trap(int* height, int heightSize){
    if (heightSize < 3) return 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0; //左边、右边最大高度
    int inflow = 0;
    while (left < right) {
        leftMax = (leftMax >= height[left] ? leftMax : height[left]);
        rightMax = (rightMax >= height[right] ? rightMax : height[right]);
        if (height[left] < height[right]) {
            inflow += leftMax - height[left];
            left++;
        } else {
            inflow += rightMax - height[right];
            right--;
        }
    }
    return inflow;
}


void trapTest() {
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(A, A + sizeof(A) / sizeof(A[0]));
//    int res = trap(height);
//    int res = trap2(height);
    int res = trap3(height);
    cout << res << endl;
}

#endif //ALGORITHM_TRAP_H
