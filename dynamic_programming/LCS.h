//
// Created by 王锐 on 2021/12/13.
// TODO 打印子串的逻辑有问题
//

#ifndef ALGORITHM_LCS_H
#define ALGORITHM_LCS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void LCS_Length(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    int c[m + 1][n + 1];
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 1; j <= n; j++) c[0][j] = 0;

    int b[m + 1][n + 1];
    for (int i = 0; i <= m; i++) b[i][0] = 0;
    for (int j = 1; j <= n; j++) b[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 10;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 12;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 9;
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << b[i][j] << "\t";
            if (j == n) cout << endl;
        }
    }
    cout << endl;
    cout << "最大公共子序列的长度为：" << c[m][n] << endl;

    int k = c[m][n] - 1;
    vector<char> ch(k + 1);
    while (true) {
        if (m == 0 || n == 0) break;
        if (b[m][n] == 10) {
            ch[k--] = X[m-1];
            cout << X[m-1];
            m--;
            n--;
        }
        else if (b[m][n] == 12) {
            m--;
        }
        else {
            n--;
        }
    }

//    for (auto cc: ch) cout << cc;
    string s(ch.begin(), ch.end());
    cout << "\n公共字符串为：" << s << endl;

}

void LCS_LengthTest() {
    string X = "ABCBDAB";
    string Y = "BDCABA";
    LCS_Length(X, Y);
}

#endif //ALGORITHM_LCS_H
