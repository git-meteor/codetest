#include <iostream>
#include <stdlib.h>

#include "Common.h"
#include "BinarySearch.h"
#include "QuickSort.h"
#include "SmallestKNumbers.h"
#include "OddBeforeEven.h"
#include "SelectKth.h"

#include "SearchRotateArray.h"

int main(int argc, char* argv[]) {

  TestCase* test_case_array[] = {
			new BinarySearchTest,
//			new QuickSortTest,
//      new SmallestKNumbersTest,
//      new SelectKthTest,
//      new OddBeforeEvenTest,
  };

  size_t size = sizeof(test_case_array) / sizeof(TestCase*);
  for (int i = 0; i < size; ++i) {
    TestCase* test_case = test_case_array[i];
    if (test_case) {
      test_case->Test();
      delete test_case;
    }
  }
//	{ SearchRotateArray test; test.Test();}
}
