#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class BubbleSort {

public:
  void Run(T num[], int n) {
    if(n <= 0){
      return;
    }
    for(int i = n - 1; i >= 0; --i){
      for(int j = 0; j < i; ++j){
        if(num[j] > num[j+1]){
          std::swap(num[j], num[j+1]);
        }
      }
    }
  }
};

#endif
