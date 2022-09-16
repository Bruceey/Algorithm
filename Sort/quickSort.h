//
// Created by 王锐 on 2021/11/17.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <cstdlib>
#include <time.h>
#include <utility>
using namespace std;

template<typename T>
int partition(T* A, int lo, int hi) {
    srand(time(nullptr));
    int index = rand() % (hi - lo + 1) + lo;
    swap(A[index], A[hi]);

    T x = A[hi];
    int i = lo - 1;
    for (int j=lo; j < hi; j++)
        if (A[j] <= x) swap(A[++i], A[j]);
    swap(A[++i], A[hi]);

    return i;
}


template<typename T>
int partition2(T* A, int lo, int hi) {
    //利用双指针
    srand(time(nullptr));
    int index = rand() % (hi - lo + 1) + lo;
    swap(A[index], A[lo]);

    T x = A[lo];
    int i = lo, j = hi;
    while (i < j) {
        while (i < j && x <= A[j]) j--;
        //此时A[j] < x，放在最左侧i处
        A[i] = A[j];
        while (i < j && A[i] <= x) i++;
        A[j] = A[i];
    }
    A[i] = x;
    return i;
}


template<typename T>
void quickSort(T* A, int lo, int hi) {
    if (lo < hi) {
//        int q = partition(A, lo, hi);
        int q = partition2(A, lo, hi);

        quickSort(A, lo, q-1);
        quickSort(A, q+1, hi);
    }
}


#endif //ALGORITHM_QUICKSORT_H
