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
//  int operator()(T num[], int left, int right, T pivot_value) {
//    int i = left;
//    int j = right;
//    while (i <= j) {
//      while (i <= right && num[i] < pivot_value) {
//        ++i;
//      }
//
//      while (j >= left && num[j] > pivot_value) {
//        --j;
//      }
//
//      if (j <= i) {
//        return i;
//      }
//
//      std::swap(num[i], num[j]);
//      ++i;
//      --j;
//    }
//
//    return i;
//  }

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

//template<typename T> class OddEventPartitioner {
//public:
//  OddEventPartitioner() {
//    ;
//  }
//
//  bool IsOdd(T value){
//    return (value & 1) != 0;
//  }
//
//  int operator()(T num[], int left, int right) {
//    int i = left;
//    int j = right;
//    while (i <= j) {
//      while (i <= right && IsOdd(num[i])) {
//        ++i;
//      }
//
//      while (j >= left && !IsOdd(num[i])) {
//        --j;
//      }
//
//      if (j <= i) {
//        return i;
//      }
//
//      std::swap(num[i], num[j]);
//      ++i;
//      --j;
//    }
//
//    return i;
//  }
//};

class TestCase {
public:
  virtual void Test() = 0;
  virtual ~TestCase() {
    ;
  }
};

#endif
