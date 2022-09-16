//
// Created by 17634 on 2022/9/14.
//

#ifndef ALGORITHM_7_REVERSE_H
#define ALGORITHM_7_REVERSE_H

//7. 整数反转
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围[−2^31, 2^31− 1] ，就返回 0
//假设环境不允许存储 64 位整数（有符号或无符号）。


#include <climits>

int reverse(int x) {
    int newNum = 0;
    while (x) {
        if (newNum > INT_MAX / 10 || newNum < INT_MIN / 10) //x是正数情况： INT_MAX左边是2，右边是7；x的最高位(恒<=2)即是新数的最低位，
            return 0;                                        //x是负数情况： INT_MIN左边是2，右边是8；x的最高位(恒<=2)即是新数的最低位，
        newNum = 10 * newNum + x % 10;
        x /= 10;
    }
    return newNum;
}

#endif //ALGORITHM_7_REVERSE_H
