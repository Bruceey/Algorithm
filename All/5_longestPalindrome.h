//
// Created by 17634 on 2022/9/13.
//

#ifndef ALGORITHM_5_LONGESTPALINDROME_H
#define ALGORITHM_5_LONGESTPALINDROME_H

#include <string>
using namespace std;

//5. 最长回文子串       最优算法Manacher 算法：较为复杂，时间O(n)，空间O(n)
//给你一个字符串 s，找到 s 中最长的回文子串。
//
// 输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。

pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (0 <= left && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return make_pair(left + 1, right - 1);
}

string longestPalindrome(string s) {
    if (s.size() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        auto l1 = expandAroundCenter(s, i, i);
        auto l2 = expandAroundCenter(s, i, i + 1);
        if (l1.second - l1.first > end - start) {
            start = l1.first;
            end = l1.second;
        }
        if (l2.second - l2.first > end - start) {
            start = l2.first;
            end = l2.second;
        }
    }
    return s.substr(start, end - start + 1);
}

#endif //ALGORITHM_5_LONGESTPALINDROME_H
