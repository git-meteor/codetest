/*
 * SearchRotateArray.h
 *
 *  Created on: 2015Äê4ÔÂ8ÈÕ
 *      Author: Meteor
 */

#ifndef SEARCHROTATEARRAY_H_
#define SEARCHROTATEARRAY_H_

#include <iostream>

class SearchRotateArray {
public:
  int Run(int nums[], int n, int v) {
    if (n <= 0) {
      return -1;
    }

    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = (right + left) / 2;

      if (v < nums[mid]) {
        if (nums[left] <= nums[mid]) {
          if (v < nums[left]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        } else {
          right = mid - 1;
        }
      } else if (v > nums[mid]) {
        if (nums[right] >= nums[mid]) {
          if (v > nums[right]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        } else {
          left = mid + 1;
        }
      } else {
        return mid;
      }
    }

    return -1;
  }

  void PrintArray(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
  }

  void Test() {
    {
      int nums[] = { 4, 5, 6, 7, 1, 2, 3 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 1 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 1, 2 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 2, 1 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 1, 2, 3 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 3, 1, 2 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int nums[] = { 2, 3, 1 };
      int n = sizeof(nums) / sizeof(int);
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }

    {
      int* nums = 0;
      int n = 0;
      PrintArray(nums, n);
      for (int i = 0; i < n; ++i) {
        std::cout << "index(" << nums[i] << "): " << Run(nums, n, nums[i]) << std::endl;
      }
    }
  }
};

#endif /* SEARCHROTATEARRAY_H_ */
