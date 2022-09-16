//
// Created by 王锐 on 2021/11/17.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H


template<typename T>
void merge(T* A, int lo, int mi, int hi) {
    int i = lo;
    int j = 0; int lb = mi - lo + 1; T B[lb];
    for (int i = 0; i < lb; i++) B[i] = A[lo + i];
    int k = 0; int lc = hi - mi; T* C = A + mi + 1;

    while (j < lb && k < lc) {
        A[i++] = B[j] <= C[k] ? B[j++] : C[k++];
    }

    while (j < lb)
        A[i++] = B[j++];
}


template<typename T>
void mergeSort(T* A, int lo, int hi) {
    if (lo < hi) {
        int mi = (lo + hi) / 2;
        mergeSort(A, lo, mi);
        mergeSort(A, mi+1, hi);
        merge(A, lo, mi, hi);
    }
}

#endif //ALGORITHM_MERGESORT_H
