#ifndef COMMON_H_
#define COMMON_H_

#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>

#define ARRAY_SIZE(a) (sizeof((a))/sizeof(int))

template<typename T> class MedianSelector {
public:
  int operator()(T num[], int left, int right) {
    return (left + right) >> 1;
  }
};

template<typename T> class Median3Selector {
public:
  int operator()(T num[], int left, int right) {
    int mid = (left + right) / 2;
    if(num[left] > num[mid]){
      std::swap(num[left], num[mid]);
    }

    if(num[mid] > num[right]){
      std::swap(num[mid], num[right]);
    }

    if(num[left] > num[mid]){
      std::swap(num[left], num[mid]);
    }

    return mid;
  }
};

template<typename T> class PivotCondition {
  T pivot_;
public:
  PivotCondition(T pivot) : pivot_(pivot){
    ;
  }
  int operator()(T value){
    return value - pivot_;
  }
};

template<typename T> class OddEvenCondition {
  bool IsOdd(T value){
    return (value & 1) != 0;
  }
public:
  int operator()(T value){
    if(IsOdd(value)){
      return -1;
    } else {
      return 1;
    }
  }
};

template<typename T> class NormalPartitioner {
public:

  template<typename Condition> int operator()(T num[], int left, int right, Condition condition) {
    int i = left;
    int j = right;
    while (i <= j) {
      while (i <= right && condition(num[i]) < 0) {
        ++i;
      }

      while (j >= left && condition(num[j]) > 0) {
        --j;
      }

      if (j <= i) {
        return i;
      }

      std::swap(num[i], num[j]);
      ++i;
      --j;
    }

    return i;
  }
};

template<typename T> class NormalPartitioner2 {
public:
  template<typename Condition> int operator()(T num[], int left, int right, Condition condition) {
    int i = left;
    int j = left;

    int flag = 0;
    while(j <= right){
      if(condition(num[j]) < 0 || (condition(num[j]) == 0 && (flag ^= 1) == 1)){
        std::swap(num[i], num[j]);
        ++i;
      }
      ++j;
    }

    return i;
  }
};

void PrintArray(int nums[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}
class TestCase {
public:
  virtual void Test() = 0;
  virtual ~TestCase() {
    ;
  }
};

class PartitionTest : public TestCase {
public:
  virtual void Test() {
    {
      int a[] = { 2, 5, 8, 9, 6, 5, 3, 5, 7, 5};
      NormalPartitioner2<int> partitioner;
      int partition_index = partitioner(a, 0, ARRAY_SIZE(a) - 1, PivotCondition<int>(5));
      std::cout << "partition_index: " << partition_index << std::endl;
      PrintArray(a, ARRAY_SIZE(a));
    }
  }
};

template<typename Sorter> class SortTest : public TestCase {
  Sorter sorter_;
public:
  virtual void Test() {
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
        sorter_.Run(a, array_size);
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

bool AssertTrue(bool expr){
  if(expr){
    return true;
  } else {
    return false;
  }
}

#endif
