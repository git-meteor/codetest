#include "Common.h"
#include <assert.h>

class BinarySearch: public TestCase {
public:
  int Run(int num[], int n, int v) {
    if (!num || n <= 0) {
      return -1;
    }

    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (v < num[mid]) {
        right = mid - 1;
      } else if (v > num[mid]) {
        left = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }

  virtual void Test() {
    {
      int *a = 0;
      assert(Run(a, 10, 5) == -1);
    }

    {
      int a[1] = { 1 };
      assert(Run(a, 0, 0) == -1);
      assert(Run(a, 0, 1) == -1);
      assert(Run(a, 0, 2) == -1);

      assert(Run(a, -1, 0) == -1);
      assert(Run(a, -1, 1) == -1);
      assert(Run(a, -1, 2) == -1);
    }

    {
      int a[1] = { 1 };
      assert(Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == -1);
    }

    {
      int a[2] = { 1, 3 };
      assert(Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(Run(a, ARRAY_SIZE(a), 4) == -1);
    }

    {
      int a[3] = { 1, 3, 5 };
      assert(Run(a, ARRAY_SIZE(a), 0) == 0);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(Run(a, ARRAY_SIZE(a), 6) == -1);
    }

    {
      int a[4] = { 1, 3, 5, 7 };
      assert(Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(Run(a, ARRAY_SIZE(a), 6) == -1);
      assert(Run(a, ARRAY_SIZE(a), 7) == 3);
      assert(Run(a, ARRAY_SIZE(a), 8) == -1);
    }

    {
      int a[5] = { 1, 3, 5, 7, 9 };
      assert(Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == -1);
      assert(Run(a, ARRAY_SIZE(a), 3) == 1);
      assert(Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(Run(a, ARRAY_SIZE(a), 5) == 2);
      assert(Run(a, ARRAY_SIZE(a), 6) == -1);
      assert(Run(a, ARRAY_SIZE(a), 7) == 3);
      assert(Run(a, ARRAY_SIZE(a), 8) == -1);
      assert(Run(a, ARRAY_SIZE(a), 9) == 4);
      assert(Run(a, ARRAY_SIZE(a), 10) == -1);
    }

    {
      int a[9] = { 1, 2, 3, 5, 6, 7, 9, 10, 12 };
      assert(Run(a, ARRAY_SIZE(a), 0) == -1);
      assert(Run(a, ARRAY_SIZE(a), 1) == 0);
      assert(Run(a, ARRAY_SIZE(a), 2) == 1);
      assert(Run(a, ARRAY_SIZE(a), 3) == 2);
      assert(Run(a, ARRAY_SIZE(a), 4) == -1);
      assert(Run(a, ARRAY_SIZE(a), 5) == 3);
      assert(Run(a, ARRAY_SIZE(a), 6) == 4);
      assert(Run(a, ARRAY_SIZE(a), 7) == 5);
      assert(Run(a, ARRAY_SIZE(a), 8) == -1);
      assert(Run(a, ARRAY_SIZE(a), 9) == 6);
      assert(Run(a, ARRAY_SIZE(a), 10) == 7);
      assert(Run(a, ARRAY_SIZE(a), 11) == -1);
      assert(Run(a, ARRAY_SIZE(a), 12) == 8);
      assert(Run(a, ARRAY_SIZE(a), 13) == -1);
    }

  }
};

