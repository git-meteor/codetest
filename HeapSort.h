#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class HeapSort {

public:
  inline int LeftChild(int i){
    return 2 * i + 1;
  }

  inline int RightChild(int i){
    return 2 * i + 2;
  }

  void PercDown(T a[], int n, int i) {
    T value = a[i];
    int j = i;
    while(LeftChild(j) < n){
      int child = LeftChild(j);
      if(RightChild(j) < n && a[RightChild(j)] > a[child]){
        child = RightChild(j);
      }

      if(value >= a[child]){
        break;
      } else {
        a[j] = a[child];
        j = child;
      }
    }
    a[j] = value;
  }

  void Run(T a[], int n) {
    std::cout << "HeapSort" << std::endl;
    if (n <= 1) {
      return;
    }

    for(int i = n / 2; i >= 0; --i) {
      PercDown(a, n, i);
    }

    for(int i = n - 1; i >= 1; --i) {
      std::swap(a[0], a[i]);
      PercDown(a, i, 0);
    }
  }
};

#endif
