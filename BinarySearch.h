#include "Common.h"
#include <assert.h>


template<typename T> class ArrayDataGetter {
  const T* nums_;
public:
  ArrayDataGetter(T nums[]) : nums_(nums){;}
  const T& operator()(int index) const{
    return nums_[index];
  }
};


template<typename T, typename DataGetter> class ValueCondition {
  const T& target_;
  const DataGetter& getter_;
public:


//  template<typename T, typename DataGetter> static ValueCondition Create(const T& target, const DataGetter& getter){
//    return ValueCondition<T, DataGetter>(target, getter);
//  }

  ValueCondition(const T& target, const DataGetter& getter) : target_(target), getter_(getter) {;}
  int operator()(int index) const {
    return target_ - getter_(index);
  }
};

template<typename T, typename DataGetter> static ValueCondition<T, DataGetter> CreateValueCondition(const T& target, const DataGetter& getter){
  return ValueCondition<T, DataGetter>(target, getter);
}

template<typename T> class BinarySearchBase{
public:
  template<typename Condition> int Search(int n, Condition& condition, bool return_insert_pos = false) {
    if(n <= 0){
      return return_insert_pos ? 0 : -1;
    }

    int left = 0;
    int right = n - 1;
    while(left <= right){
      int mid = (left + right) >> 1;
      if(condition(mid) == 0){
        return mid;
      } else if(condition(mid) < 0){
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return return_insert_pos ? left : -1;

  }
};


template<typename T> class BinarySearch : private BinarySearchBase<T>{
public:
  int Run(T nums[], int n, T target) {
    if(!nums){
      return -1;
    }

    ArrayDataGetter<T> getter(nums);
    return Search(n, CreateValueCondition(target, getter));
  }
};

class BinarySearchTest : public TestCase {
public:

  virtual void Test() {

    BinarySearch<int> search;

    {
      int *a = 0;
      assert(search.Run(a, 10, 5) == -1);
    }

    {
      int a[1] = { 1 };
      assert(search.Run(a, 0, 0) == -1);
      assert(search.Run(a, 0, 1) == -1);
      assert(search.Run(a, 0, 2) == -1);

      assert(search.Run(a, -1, 0) == -1);
      assert(search.Run(a, -1, 1) == -1);
      assert(search.Run(a, -1, 2) == -1);
    }

    {
      int a[1] = { 1 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == -1);
    }

    {
      int a[2] = { 1, 3 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(search.Run(a, ARRAY_SIZE(a), 4) == -1);
    }

    {
      int a[3] = { 1, 3, 5 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(search.Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(search.Run(a, ARRAY_SIZE(a), 6) == -1);
    }

    {
      int a[4] = { 1, 3, 5, 7 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(search.Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(search.Run(a, ARRAY_SIZE(a), 6) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 7) == 3);
      assert(search.Run(a, ARRAY_SIZE(a), 8) == -1);
    }

    {
      int a[5] = { 1, 3, 5, 7, 9 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(search.Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(search.Run(a, ARRAY_SIZE(a), 6) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 7) == 3);
      assert(search.Run(a, ARRAY_SIZE(a), 8) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 9) == 4);
      assert(search.Run(a, ARRAY_SIZE(a), 10) == -1);
    }

    {
      int a[9] = { 1, 2, 3, 5, 6, 7, 9, 10, 12 };
      assert(search.Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(search.Run(a, ARRAY_SIZE(a), 2) == 1);
      assert(search.Run(a, ARRAY_SIZE(a), 3) == 2);
      assert(search.Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 5) == 3);
      assert(search.Run(a, ARRAY_SIZE(a), 6) == 4);
      assert(search.Run(a, ARRAY_SIZE(a), 7) == 5);
      assert(search.Run(a, ARRAY_SIZE(a), 8) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 9) == 6);
      assert(search.Run(a, ARRAY_SIZE(a), 10) == 7);
      assert(search.Run(a, ARRAY_SIZE(a), 11) == -1);
      assert(search.Run(a, ARRAY_SIZE(a), 12) == 8);
      assert(search.Run(a, ARRAY_SIZE(a), 13) == -1);
    }

  }
};

