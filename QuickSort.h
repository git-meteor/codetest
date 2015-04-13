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

class QuickSortTest: public TestCase {
  virtual void Test() {
    QuickSort<int, MedianSelector<int>, NormalPartitioner2<int> > sorter;
//		QuickSort<int> sorter;

    srand(12345);
    int test_count = 10;
    int max_array_size = 10;
    for (int i = 0; i < test_count; ++i) {
      for (int j = 1; j <= max_array_size; ++j) {
        int array_size = j;
        int* a = new int[array_size];

        for (int k = 0; k < array_size; ++k) {
          a[k] = rand() % array_size;
        }

        std::cout << "Before sort: ";
        PrintArray(a, array_size);
        sorter.Run(a, array_size);
        std::cout << "After sort: ";
        PrintArray(a, array_size);
        assert(IsSorted(a, array_size));

        delete a;
      }
    }
  }

  bool IsSorted(int num[], int n) {
    if (n == 1) {
      return true;
    }

    for (int i = 1; i < n; ++i) {
      if (num[i] < num[i - 1]) {
        return false;
      }
    }

    return true;
  }
};

