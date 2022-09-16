//
// Created by 王锐 on 2021/11/18.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H
using namespace std;
#include <vector>

template<typename T>
void maxHeap(T* A, int i, int heapSize) {
    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    if (lc < heapSize && A[lc] > A[largest])
        largest = lc;
    if (rc < heapSize && A[rc] > A[largest])
        largest = rc;
    if (largest != i) {
        swap(A[largest], A[i]);
        maxHeap(A, largest, heapSize);
    }
}

template<typename T>
void heapSort(T* A, int n) {
    //建堆
    for (int i = (n-1-1)/2; i >= 0; i--) {
        maxHeap(A, i, n);
    }

    //输出
    for (int i = n-1; i > 0; i--) {
        swap(A[0], A[i]);
        maxHeap(A, 0, i);
    }
}


template<typename T>
//vector<T> minK(T* A, int n, int k) {
T* minK(T* A, int n, int k) {
    T* B = new T[k];
//    T B[k];
    for (int i=0; i<k; i++) B[i] = A[i];

    //建堆
    for (int i = (k-1-1)/2; i >= 0; i--) {
        maxHeap(B, i, k);
    }

    //维护
    for (int i = k; i < n; i++) {
        if (A[i] < B[0]) {
            B[0] = A[i];
            maxHeap(B, 0, k);
        }
    }

    //输出，可以直接输出、也可以排序后输出
    //return B;
    for (int i = k-1; i > 0; i--) {
        swap(B[0], B[i]);
        maxHeap(B, 0, i);
    }
//    vector<T> res(k);
//    for (int i = 0; i < k; i++)
//        res[i] = B[i];
//    return res;
//
//    return res;
    return B;
}

#endif //ALGORITHM_HEAPSORT_H
