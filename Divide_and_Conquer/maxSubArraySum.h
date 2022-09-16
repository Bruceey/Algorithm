//
// Created by 王锐 on 2021/11/19.
//

#ifndef ALGORITHM_MAXSUBARRAYSUM_H
#define ALGORITHM_MAXSUBARRAYSUM_H


int findMaxSumCorssSubArray(const int* A, int lo, int mi, int hi) {
    int sum = A[mi];
    int leftMaxSum = A[mi];
    for (int i = mi-1; i >= lo; i--) {
        sum += A[i];
        if (leftMaxSum < sum) leftMaxSum = sum;
    }

    sum = A[mi+1];
    int rightMaxSum = sum;
    for (int i = mi+2; i <= hi; i++) {
        sum += A[i];
        if (rightMaxSum < sum) rightMaxSum = sum;
    }
    return leftMaxSum + rightMaxSum;
}



int maxSubArraySum(int* A, int lo, int hi) {
    if (hi - lo < 1) return A[lo];

    int mi = (lo + hi) / 2;
    int leftMaxSum = maxSubArraySum(A, lo, mi);
    int rightMaxSum = maxSubArraySum(A, mi+1, hi);
    int crossMaxSum = findMaxSumCorssSubArray(A, lo, mi, hi);

    if (leftMaxSum >= rightMaxSum && leftMaxSum >= crossMaxSum) return leftMaxSum;
    else if (rightMaxSum >= crossMaxSum) return rightMaxSum;
    else return crossMaxSum;
}

#endif //ALGORITHM_MAXSUBARRAYSUM_H
