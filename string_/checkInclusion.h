//
// Created by 王锐 on 2021/11/30.
//

#ifndef ALGORITHM_CHECKINCLUSION_H
#define ALGORITHM_CHECKINCLUSION_H
#include <string>
#include <iostream>
using namespace std;


bool areAllZero(const int* counts, int n) {
    for (int i = 0; i < n; i++)
        if (counts[i] != 0) return false;
    return true;
}

// 字符串s1和s2(里面只包含26个小写字母)，判断字符串s2中是否包含s1的某个变位词
bool checkInclusion(const string& s1, const string& s2) {
    if (s1.size() > s2.size()) return false;

    int k = 26;
    int* counts = new int[k]();

    for(int i = 0; i < s1.length(); i++) {
        counts[s1[i] - 'a']++;
        counts[s2[i] - 'a']--;
    }

    if (areAllZero(counts, k)) {
        delete[] counts;
        return true;
    }

    for (int i = s1.length(); i < s2.length(); i++) {
        counts[s2[i] - 'a']--;
        counts[s2[i-s1.length()] - 'a']++;
        if (areAllZero(counts, k)) {
            delete [] counts;
            return true;
        }
    }

    delete [] counts;
    return false;
}

void checkInclusionTest() {
    string s1 = "ab";
    string s2 = "eidboaoo";
    bool res = checkInclusion(s1, s2);
    cout << res << endl;
}


#endif //ALGORITHM_CHECKINCLUSION_H
