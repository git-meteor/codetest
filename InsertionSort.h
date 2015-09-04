#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class InsertionSort {

public:
  void Run(T num[], int n) {
    // �����ݽṹ���㷨����-C������������2�� P166
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
