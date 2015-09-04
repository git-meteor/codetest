#include "Common.h"
#include <assert.h>
#include <vector>
#include <algorithm>

template<typename T, class PivotSelector, class Partitioner> class SmallestKNumbers {
  PivotSelector pivot_selector_;
  Partitioner partitioner_;

public:
  SmallestKNumbers() {
    ;
  }

  void Find(T num[], int left, int right, int k) {
    if (k <= 0) {
      return;
    }

    // NOTE 注意当k大于元素个数时，则不需要进行处理
    if (k >= (right - left + 1)) {
      return;
    }

    if (left >= right) {
      return;
    }

    int pivot_index = pivot_selector_(num, left, right);

    std::swap(num[pivot_index], num[right]);
    PivotCondition<T> condition(num[right]);
    int partition_index = partitioner_(num, left, right - 1, condition);
    std::swap(num[partition_index], num[right]);

    // NOTE 注意区分各种情况

    int remain = k - (partition_index - left + 1);

    if (remain == 0 || remain == -1) {
      return;
    } else if (remain < -1) {
      Find(num, left, partition_index - 1, k);
    } else {
      Find(num, partition_index + 1, right, remain);
    }
  }

  void Run(T num[], int n, int k, T result[]) {
    Find(num, 0, n - 1, k);
    // NOTE 注意当k大于数组长度时，只输出所有数组元素
    for (int i = 0; i < k && i < n; ++i) {
      result[i] = num[i];
    }
  }
};

class SmallestKNumbersTest: public TestCase {
  virtual void Test() {
    SmallestKNumbers<int, Median3Selector<int>, NormalPartitioner2<int> > finder;
//		QuickSort<int> sorter;

    srand(12345);
    int test_count = 10;
    int max_array_size = 10;
    for (int i = 0; i < test_count; ++i) {
      std::cout << "Test round " << i << std::endl;
      for (int j = 1; j <= max_array_size; ++j) {
        int array_size = j;
        int* a = new int[array_size];

        for (int k = 0; k < array_size; ++k) {
          a[k] = rand() % array_size;
        }

        std::cout << "Array: ";
        PrintArray(a, array_size);

        std::vector<int> ref_sorted_array(a, a + array_size);
        std::sort(ref_sorted_array.begin(), ref_sorted_array.end());

        for (int k = 0; k <= array_size + 1; ++k) {
          int* result = new int[k];
          finder.Run(a, array_size, k, result);
          std::cout << k << " smallest numbers: ";
          int result_size = std::min(k, array_size);
          PrintArray(result, result_size);

          std::vector<int> test_sorted_array(result, result + result_size);
          std::sort(test_sorted_array.begin(), test_sorted_array.end());

          for (int m = 0; m < k && m < array_size; ++m) {
//						std::cout << test_sorted_array[m] << " vs " << ref_sorted_array[m] << std::endl;
            assert(ref_sorted_array[m] == test_sorted_array[m]);
          }

          delete result;
        }

        delete a;

        std::cout << std::endl;
      }
    }
  }
};

