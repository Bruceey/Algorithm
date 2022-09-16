//
// Created by 王锐 on 2021/12/1.
//

#ifndef ALGORITHM_FINDANAGRAMS_H
#define ALGORITHM_FINDANAGRAMS_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool areAllZeros(vector<int> &counts) {
    for (int &count: counts) {
        if (count != 0) return false;
    }
    return true;
}


// s1的长度大于s2，求s2中所有变位词在s1尚未下标，均为小写字母
vector<int> findAnagrams(string s1, string s2) {
    vector<int> res;
    if (s1.length() < s2.length()) return res;

    vector<int> counts(26);
    int i = 0;
    for (; i < s2.length(); i++) {
        counts[s2[i] - 'a']++;
        counts[s1[i] - 'a']--;
    }

    if (areAllZeros(counts)) res.emplace_back(0);

    for (; i < s1.length(); i++) {
        counts[s1[i] - 'a']--;
        counts[s1[i - s2.length()] - 'a']++;
        if (areAllZeros(counts)) res.emplace_back(i - s2.length() + 1);
    }

    return res;
}

void findAnagramsTest() {
    string s1 = "abab";
    string s2 = "abc";
    vector<int> res = findAnagrams(s1, s2);
    for(int& r: res) cout << r << ' ';

    if (res.empty()) cout << "是空的";
}


#endif //ALGORITHM_FINDANAGRAMS_H
