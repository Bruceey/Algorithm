//
// Created by 王锐 on 2021/12/12.
//

#ifndef ALGORITHM_BOTTOMUPCUTROD_H
#define ALGORITHM_BOTTOMUPCUTROD_H

#include <iostream>
#include <vector>

using namespace std;


int bottomUpCutRod(vector<int> &p, int n) {
    int r[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}

void print_cut_rod_solution(vector<int>&p, int n) {
    //r为长度为i的钢条对应的最优解，s为最优解对应的第一条钢条的切割长度
    int r[n + 1], s[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++) {
            if (i == 11) {
                cout << p[i] << "+" << r[j-i] << " = " << p[i] + r[j-i] << endl;
            }

            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    cout << "最优收益为：" << r[n] << endl;
    // 对应最优解切割长度
    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;

}

void bottomUpCutRodTest() {
    int A[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    // p是每段长度的价格
    vector<int> p(A, A + sizeof(A) / sizeof(A[0]));
    //n是钢条的总长度

    int n = 25;
    print_cut_rod_solution(p, n);
//    for (int n = 1; n <= 10; n++) {
//        int res = bottomUpCutRod(p, n);
//        cout << res << endl;
//    }
}


#endif //ALGORITHM_BOTTOMUPCUTROD_H
