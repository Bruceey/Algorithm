//
// Created by 王锐 on 2021/12/5.
//

#ifndef ALGORITHM_LONGESTPALINDROME_H
#define ALGORITHM_LONGESTPALINDROME_H
#include <string>
#include <iostream>
using namespace std;

//5. 最长回文子串
//给你一个字符串 s，找到 s 中最长的回文子串。
//输入：s = "babad"
//输出："bab"

// 方法一：动态规划 时间O(n^2) 空间O(n^2)
string longestPalindrome(const string& s) {
    int n = s.length();
    if (n == 1) return s;
    int pd[n][n];
    for (int i = 0; i < n; i++) pd[i][i] = true;

    int begin = 0;
    int maxlen = 1;
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n; i++) {
            // 长度末端
            int j = i + L - 1;
            if (j >= n) break;

            if (s[i] != s[j]) {
                pd[i][j] = false;
            } else {
                if (L <= 3) pd[i][j] = true;
                else pd[i][j] = pd[i+1][j-1];
            }

            // 判断是否大于maxLen
            if (pd[i][j] && L > maxlen) {
                begin = i;
                maxlen = L;
            }
        }
    }
    return s.substr(begin, maxlen);
}

// 方法二：中心扩展法,时间复杂度O(n^2)，空间O(1)
int expandAroundCenter(const string& s, int i, int j);

string longestPalindrome2(const string& s) {
    int n = s.length();
    if (n < 2) return s;

    int begin = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (maxLen < len) {
            begin = i - (len - 1) / 2;
            maxLen = len;
        }
    }
    return s.substr(begin, maxLen);
}

int expandAroundCenter(const string& s, int i, int j) {
    while (0 <= i && j < s.length() && s[i] == s[j]) {
        i--;
        j++;
    }
    return j - i - 1;
}


void longestPalindromeTest() {
    string s = "babad";
    string res = longestPalindrome2(s);
    cout << res << endl;
}

#endif //ALGORITHM_LONGESTPALINDROME_H
