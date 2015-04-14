#include "Common.h"
#include <assert.h>
#include <vector>
#include <algorithm>

template<typename T, class PivotSelector, class Partitioner> class SelectKth {
  PivotSelector pivot_selector_;
  Partitioner partitioner_;

public:
  SelectKth() {
    ;
  }

  bool Find(T num[], int left, int right, int k, T* result) {
    // NOTE 注意当k大于元素个数时，则不需要进行处理
    if (k <= 0 || k > (right - left + 1)) {
      return false;
    }

    if (left > right) {
      return false;
    }

    int pivot_index = pivot_selector_(num, left, right);

    std::swap(num[pivot_index], num[right]);
    PivotCondition<T> condition(num[right]);
    int partition_index = partitioner_(num, left, right - 1, condition);
    std::swap(num[partition_index], num[right]);

    int diff = k - (partition_index - left + 1);

    if(diff == 0){
      *result = num[partition_index];
      return true;
    } else if(diff > 0){
      return Find(num, partition_index + 1, right, diff, result);
    } else {
      return Find(num, left, partition_index - 1, k, result);
    }
  }

  bool Run(T num[], int n, int k, T* result) {
    return Find(num, 0, n - 1, k, result);
  }
};

class SelectKthTest: public TestCase {
  virtual void Test() {
    SelectKth<int, Median3Selector<int>, NormalPartitioner2<int> > finder;

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

        for (int k = 1; k <= array_size + 1; ++k) {
          int result = -1;
          bool success = finder.Run(a, array_size, k, &result);
          std::cout << k << "(th) number: " << result << " is success: " << std::boolalpha << success << std::endl;

          if(k > array_size){
            assert(!success);
          } else {
            assert(success);
//            std::cout << result << " vs " << ref_sorted_array[k - 1] << std::endl;
            assert(result == ref_sorted_array[k - 1]);
          }
        }

        delete a;

        std::cout << std::endl;
      }
    }
  }
};

