#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class ShellSort {

public:
  void Run(T num[], int n) {
    // �����ݽṹ���㷨����-C������������2�� P168
    T tmp;
    int k;
    for(int i = n >> 1; i > 0; i >>= 1){
      for(int j = i; j < n; ++j){
        tmp = num[j];
        for(k = j; k >= i && num[k - i] > tmp; k -= i){
          num[k] = num[k - 1];
        }
        num[k] = tmp;
      }
    }
  }
};

#endif
