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

#endif
