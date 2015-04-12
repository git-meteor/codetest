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

template<typename T> class NormalPartitioner {
public:
  NormalPartitioner() {
    ;
  }
  int operator()(T num[], int left, int right, T pivot_value) {
    int i = left;
    int j = right;
    while (i <= j) {
      while (i <= right && num[i] < pivot_value) {
        ++i;
      }

      while (j >= left && num[j] > pivot_value) {
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

class TestCase {
public:
  virtual void Test() = 0;
  virtual ~TestCase() {
    ;
  }
};

#endif
