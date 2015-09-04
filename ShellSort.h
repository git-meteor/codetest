#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class ShellSort {

public:
  void Run(T num[], int n) {
    // 《数据结构与算法分析-C语言描述》第2版 P168
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
