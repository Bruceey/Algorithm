//
// Created by 王锐 on 2022/9/18.
//

#ifndef ALGORITHM_557_REVERSEWORDS_H
#define ALGORITHM_557_REVERSEWORDS_H

#include <string>
using namespace std;

/*
 557. 反转字符串中的单词 III
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 示例 1：

输入：s = "Let's take LeetCode contest"
输出：    "s'teL ekat edoCteeL tsetnoc"
 * */

string reverseWords(string s) {
    int length = s.size();
    int i = 0;
    while (i < length) {
        int start = i;
        while (i < length && s[i] != ' ') i++;
        int left = start, right = i - 1;
        while (left < right) swap(s[left++], s[right--]);
        while (i < length && s[i] == ' ') i++;
    }
    return s;
}

#endif //ALGORITHM_557_REVERSEWORDS_H
