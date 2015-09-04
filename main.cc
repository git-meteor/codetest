#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

#include "Common.h"
#include "BinarySearch.h"
#include "QuickSort.h"
#include "SmallestKNumbers.h"
#include "OddBeforeEven.h"
#include "SelectKth.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "ReverseList.h"

#include "SearchRotateArray.h"
#include "MultiplyStrings.h"

int bst(int n){
  if(n <= 0){
      return 0;
  }
  std::vector<int> sum(n);
  std::vector<int> value(n);
  value[1] = 1;
  sum[1] = 1;

  for(int i = 2; i <= n; ++i){
      value[i] = value[i - 1] + sum[i - 1];
      sum[i] = sum[i - 1] + value[i];
      std::cout << value[i] << ", " << sum[i] << std::endl;
  }
  return value[n];
}

void RedirectStdinToFile(const std::ifstream& ifs){
//  std::streambuf *backup = std::cin.rdbuf();   // back up cin's streambuf
  std::cin.rdbuf(ifs.rdbuf()); // assign file's streambuf to cin
//  // ... cin will read from file
//  cin.rdbuf(backup);
}

int main(int argc, char* argv[]) {
//  std::ifstream ifs;
//  ifs.open("test/ReverseList.txt");
//  RedirectStdinToFile(ifs);
//  RevertListTest();
//  ifs.close();

//  std::ifstream ifs;
//  ifs.open("test/KthReverseList.txt");
//  RedirectStdinToFile(ifs);
//  KthRevertListTest();
//  ifs.close();

  std::ifstream ifs;
  ifs.open("test/ReversePartList.txt");
  RedirectStdinToFile(ifs);
  ReversePartListTest();
  ifs.close();
  return 0;

//  Solution s;
//  std::string str1 = "0";
//  std::string str2 = "0";
////  s.multiply(str1, str2);
//  std::cout << "result: " << s.multiply(str1, str2) << std::endl;
//  return 0;
//
//  int m = 2;
//  int n = 3;
//
//  int *b = new int[m];
//
//
////  int (*a)[n] = new int[m][n];
////  a[0][0] = 1;
////
////  delete []a;
//
//  return 0;
//  bst(6);
//  return 0;



  TestCase* test_case_array[] = {
//			new BinarySearchTest,
//			new QuickSortTest,
//      new SmallestKNumbersTest,
//      new SelectKthTest,
//      new OddBeforeEvenTest,
//			new PartitionTest,
//      new InsertionSortTest,
//      new SortTest<QuickSort<int, Median3Selector<int>, NormalPartitioner2<int> > >,
//      new SortTest<HandWriteQuickSort2>,
//      new SortTest<BubbleSort<int> >,
      new SortTest<HeapSort<int> >,


      //      new SortTest<InsertionSort<int> >,
//      new SortTest<ShellSort<int> >,
//      new SortTest<MergeSort<int> >,
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
