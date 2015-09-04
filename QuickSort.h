#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T, class PivotSelector, class Partitioner> class QuickSort {
  PivotSelector pivot_selector_;
  Partitioner partitioner_;

public:
  QuickSort() {
    ;
  }

  void Sort(T num[], int left, int right) {
    if (left < right) {
      int pivot_index = pivot_selector_(num, left, right);

      std::swap(num[pivot_index], num[right]);
      PivotCondition<T> condition(num[right]);
      int partition_index = partitioner_(num, left, right - 1, condition);

      std::swap(num[partition_index], num[right]);
      Sort(num, left, partition_index - 1);
      Sort(num, partition_index + 1, right);
    }
  }

  void Run(T num[], int n) {
    Sort(num, 0, n - 1);
  }
};

class HandWriteQuickSort {
public:
  void Run(int a[], int n) {
    Sort(a, 0, n - 1);
  }
  void Sort(int a[], int left, int right) {
    if(left < right) {
      int pivot_index = GetPivotIndex(left, right);
      int partition_index = Partition(a, left, right, pivot_index);
      Sort(a, left, partition_index - 1);
      Sort(a, partition_index + 1, right);
    }
  }

  int GetPivotIndex(int left, int right){
    return (left + right) / 2;
  }

  int Partition(int a[], int left, int right, int pivot_index) {
    std::swap(a[pivot_index], a[right]);
    int i = left;
    int j = left;
    while(j < right){
      if(a[j] < a[right]){
        std::swap(a[i], a[j]);
        ++i;
      }
      ++j;
    }
    std::swap(a[i], a[right]);
    return i;
  }
};

class HandWriteQuickSort2 {
public:
  void Run(int a[], int n) {
    Sort(a, 0, n - 1);
    std::cout << "HandWriteQuickSort2" << std::endl;
  }
  void Sort(int a[], int left, int right) {
    if(left < right) {
      int pivot_index = (left + right) / 2;
      std::swap(a[pivot_index], a[right]);
      int i = left, j = left;
      while(j < right) {
        if(a[j] < a[right]) {
          std::swap(a[i], a[j]);
          ++i;
        }
        ++j;
      }
      std::swap(a[i], a[right]);
      Sort(a, left, i-1);
      Sort(a, i+1, right);
    }
  }
};

#endif
