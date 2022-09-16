//
// Created by 王锐 on 2021/12/4.
//

#ifndef ALGORITHM_LARGESTRECTANGLEAREA_H
#define ALGORITHM_LARGESTRECTANGLEAREA_H

//剑指 Offer II 039. 直方图最大矩形面积
//给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//
//求在该柱状图中，能够勾勒出来的矩形的最大面积。

//输入：heights = [2,1,5,6,2,3]
//输出：10

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// 方法1：分而治之
int divideAndConquer(vector<int>& heights, int lo, int hi) {
    if (lo == hi) return 0;
    if (lo + 1 == hi) return heights[lo];

    int minIndex = lo;
    int minHeight = heights[lo];

    for (int i = lo + 1; i < hi; i++) {
        if (heights[i] < minHeight) {
            minHeight = heights[i];
            minIndex = i;
        }
    }

    // 1、以minHeight为高的整个长度的矩形
    int areaMax = minHeight * (hi - lo);
    int leftArea = divideAndConquer(heights, lo, minIndex);
    int rightArea = divideAndConquer(heights, minIndex + 1, hi);

    if (areaMax < leftArea) areaMax = leftArea;
    if (areaMax < rightArea) areaMax = rightArea;
    return areaMax;
}

// 方法2： 单调递增栈
int monotoneIncressingStack(vector<int>& heights) {
    stack<int> stk;
    stk.push(-1);

    int maxArea = 0;
    int i = 0; int height, width;
    for (; i < heights.size(); i++) {
        while (stk.top() != -1 && heights[stk.top()] > heights[i]) {
            height = heights[stk.top()]; stk.pop();
            width = i - stk.top() - 1;
            maxArea = max(height * width, maxArea);
        }
        stk.push(i);
    }
    //上方for循环完后只剩下栈里面的单调递增元素
    while (stk.top() != -1) {
        height = heights[stk.top()]; stk.pop();
        width = i - stk.top() - 1;
        maxArea = max(height * width, maxArea);
    }
    return maxArea;
}


int largestRectangleArea(vector<int>& heights) {
//    return divideAndConquer(heights, 0, heights.size());
    return monotoneIncressingStack(heights);
}


// 矩阵中的最大矩阵
//剑指 Offer II 040. 矩阵中最大的矩形
int maximalRectangle(vector<string>& matrix) {
    if (matrix.empty() || matrix[0].length() == 0) return 0;
    vector<int> heights(matrix[0].length());
    int maxArea = 0;
    for (auto& row: matrix) {
        for (int i = 0; i < row.length(); i++) {
            if (row[i] == '0') heights[i] = 0;
            else heights[i]++;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

void largestRectangleAreaTest() {
//    int A[] = {2,1,5,6,2,3};
    int A[] = {2, 1, 2};
    vector<int> heights(A, A + sizeof(A) / sizeof(A[0]));
    int res = largestRectangleArea(heights);
    cout << "最大面积为：" << res << endl;
}


void maximalRectangleTest() {
    string A[] = {"10100","10111","11111","10010"};
    vector<string> heights(A, A + sizeof(A) / sizeof(A[0]));
    int res = maximalRectangle(heights);
    cout << "最大面积为：" << res << endl;
}


#endif //ALGORITHM_LARGESTRECTANGLEAREA_H
