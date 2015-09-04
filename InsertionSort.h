#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class InsertionSort {

public:
  void Run(T num[], int n) {
    // 《数据结构与算法分析-C语言描述》第2版 P166
    T tmp;
    int j;
    for(int i = 1; i < n; ++i){
      tmp = num[i];
      for(j = i; j > 0 && num[j - 1] > tmp; --j) {
        num[j] = num[j - 1];
      }
      num[j] = tmp;
    }
  }
};

#endif
