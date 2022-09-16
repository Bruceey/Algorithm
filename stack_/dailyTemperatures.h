//
// Created by 王锐 on 2021/12/4.
//

#ifndef ALGORITHM_DAILYTEMPERATURES_H
#define ALGORITHM_DAILYTEMPERATURES_H
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//剑指 Offer II 038. 每日温度
//请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。

//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]

vector<int> dailyTemperatures(vector<int>& temperatures){
    vector<int> res(temperatures.size());
    stack<int> stk;  //存的每日温度的下标
    for (int i = 0; i < temperatures.size(); i++) {
        while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
            res[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

void dailyTemperaturesTest() {
    int A[] = {73,74,75,71,69,72,76,73};
    vector<int> temperatures(A, A + sizeof(A) / sizeof(A[0]));
    vector<int> res = dailyTemperatures(temperatures);

    for (auto& x: res) cout << x << " ";
}

#endif //ALGORITHM_DAILYTEMPERATURES_H
