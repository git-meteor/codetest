#include "Common.h"
#include <assert.h>
#include <vector>
#include <algorithm>

template<typename T, class Partitioner> class OddBeforeEven {
  Partitioner partitioner_;
public:
  int Run(T num[], int n) {
    return partitioner_(num, 0, n - 1, OddEvenCondition<T>());
  }
};

class OddBeforeEvenTest: public TestCase {
  virtual void Test() {
    OddBeforeEven<int, NormalPartitioner2<int> > swapper;

    srand(12345);
    int test_count = 10;
    int max_array_size = 10;
    for (int i = 0; i < test_count; ++i) {
      std::cout << "Test round " << i << std::endl;
      for (int j = 1; j <= max_array_size; ++j) {
        int array_size = j;
        int* a = new int[array_size];

        for (int k = 0; k < array_size; ++k) {
          a[k] = rand() % array_size;
        }

        std::cout << "Array: ";
        PrintArray(a, array_size);

        int partition_index = swapper.Run(a, array_size);
        std::cout << "Array after swap: ";
        PrintArray(a, array_size);

        for(int i = 0; i < partition_index; ++i){
          assert((a[i] & 1) != 0);
        }

        for(int i = partition_index; i < array_size; ++i){
          assert((a[i] & 1) == 0);
        }

        delete a;

        std::cout << std::endl;
      }
    }
  }
};

