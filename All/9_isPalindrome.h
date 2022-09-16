//
// Created by 17634 on 2022/9/13.
//

#ifndef ALGORITHM_9_ISPALINDROME_H
#define ALGORITHM_9_ISPALINDROME_H

#include <vector>
using namespace std;

//9. 回文数
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

//注意：完全翻转过来可能超出int类型范围，故翻转一般，当 旧数<=新数 即翻转到一半了

bool isPalindrome(int x) {  //x的位数分奇数和偶数两种情况
    if (x < 0) return false;
    if (x == 0) return true;
    if (x % 10 == 0) return false;
    int newNum = 0;
    while (x > newNum) {
        newNum = 10 * newNum + x % 10;
        x /= 10;
    }
    if (newNum == x || newNum / 10 == x) return true;
    return false;
}

//再简化
bool isPalindrome2(int x) {  //x的位数分奇数和偶数两种情况
    if (x < 0 || x % 10 == 0 && x != 0) return false;
    int newNum = 0;
    while (x > newNum) {
        newNum = 10 * newNum + x % 10;
        x /= 10;
    }
    return newNum == x || newNum / 10 == x;
}
#endif //ALGORITHM_9_ISPALINDROME_H
