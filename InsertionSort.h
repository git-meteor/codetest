#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "Common.h"
#include <assert.h>

template<typename T> class InsertionSort {

public:
  void Run(T num[], int n) {
    // 《数据结构与算法分析-C语言描述》第2版 P166
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

class InsertionSortTest: public TestCase {
  virtual void Test() {
    InsertionSort<int> sorter;
//		InsertionSort<int> sorter;

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

#endif

