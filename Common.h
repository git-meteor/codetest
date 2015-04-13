#ifndef COMMON_H_
#define COMMON_H_

#define ARRAY_SIZE(a) (sizeof((a))/sizeof(int))

template<typename T> class MedianSelector {
public:
  MedianSelector() {
    ;
  }
  int operator()(T num[], int left, int right) {
    return (left + right) >> 1;
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

#endif
