//
// Created by 17634 on 2022/9/13.
//

#ifndef ALGORITHM_3_LENGTHOFLONGESTSUBSTRING_H
#define ALGORITHM_3_LENGTHOFLONGESTSUBSTRING_H

#include <string>
#include <map>
#include <unordered_set>
using namespace std;

//3. 无重复字符的最长子串
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

//滑动窗口
int lengthOfLongestSubstring2(string s) {
    if (s.size() == 0) return 0;
    unordered_set<char> M;
    int maxLen = 0;
    int i = 0, j = 0;
    while (j < s.length()) {
        while (M.find(s[j]) != M.end()) //M中已存在该字符
            M.erase(s[i++]); //删除M中最左边的元素
        maxLen = max(maxLen, j - i + 1);
        M.insert(s[j++]);
    }
    return maxLen;
}

int lengthOfLongestSubstring(string &s) {
    map<char, int> M;
    if (s.size() < 2) return s.size();
    int maxLen = 0;
    int i = 0, j = 0;
    while (j < s.size()) {
        if (M.find(s[j]) == M.end())
            M[s[j]] = j;
        else { //s[j]此时必然存在
            if (M[s[j]] >= i) {
                maxLen = j - i > maxLen ? j - i : maxLen;
                i = M[s[j]] + 1;
            }
            M[s[j]] = j; //即时更新字符s[j]的新位置j
        }
        j++;
    }
    maxLen = j - i > maxLen ? j - i : maxLen;
    return maxLen;
}

#endif //ALGORITHM_3_LENGTHOFLONGESTSUBSTRING_H
