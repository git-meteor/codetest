#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class MergeSort {

public:
  void Sort(T num[], int left, int right, T tmp[]) {
    if(left == right){
      return;
    }

    int mid = (left + right) >> 1;

    Sort(num, left, mid, tmp);
    Sort(num, mid + 1, right, tmp);
    Merge(num, left, mid, mid + 1, right, tmp);
    std::copy(tmp, tmp + (right - left + 1), &num[left]);
  }

  void Merge(T num[], int left1, int right1, int left2, int right2, T tmp[]){
    int i = left1;
    int j = left2;
    int k = 0;
    while(i <= right1 && j <= right2){
      if(num[i] < num[j]){
        tmp[k++] = num[i++];
      } else {
        tmp[k++] = num[j++];
      }
    }

    while(i <= right1){
      tmp[k++] = num[i++];
    }

    while(j <= right2){
      tmp[k++] = num[j++];
    }
  }

  void Run(T num[], int n) {
    T* tmp = new T[n];
    Sort(num, 0, n - 1, tmp);
  }
};

#endif
