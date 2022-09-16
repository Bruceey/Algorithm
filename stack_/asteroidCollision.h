//
// Created by 王锐 on 2021/12/3.
//

#ifndef ALGORITHM_ASTEROIDCOLLISION_H
#define ALGORITHM_ASTEROIDCOLLISION_H

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

// 剑指 Offer II 037. 小行星碰撞
// 给定一个整数数组 asteroids，表示在同一行的小行星。
//
//对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
//
//找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

//输入：asteroids = [5,10,-5]
//输出：[5,10]
//解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stk;
    for (auto x: asteroids) {
        while (!stk.empty() && stk.back() > 0 && stk.back() < -x) stk.pop_back();
        if (!stk.empty() && stk.back() > 0 && stk.back() == -x) stk.pop_back();
        else if (x > 0 || stk.empty() || stk.back() < 0) stk.emplace_back(x);
    }
    return stk;
}

void asteroidCollisionTest() {
//    int A[] = {5,10,-5};
    int A[] = {-2,-1,1,2};
    vector<int> asteroids(A, A + sizeof(A) / sizeof(A[0]));
    vector<int> res = asteroidCollision(asteroids);

    for (auto& x: res) cout << x << " ";
}

#endif //ALGORITHM_ASTEROIDCOLLISION_H
