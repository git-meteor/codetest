#include "Common.h"
#include <assert.h>

class QuickSort : public TestCase {
public:

	void Sort(int num[], int left, int right){
		if(left < right){
			int pivot_index = SelectPivot(num, left, right);
			std::swap(num[pivot_index], num[right]);
			int partition_index = Partition(num, left, right - 1, num[right]);
			std::swap(num[partition_index], num[right]);
			Sort(num, left, partition_index - 1);
			Sort(num, partition_index + 1, right);
		}
	}


	int SelectPivot(int num[], int left, int right){
		return (left + right) >> 1;
	}

	int Partition(int num[], int left, int right, int pivot_value){
		int i = left;
		int j = right;
		while(i <= j){
			while(i <= right && num[i] < pivot_value){
				++i;
			}

			while(j >= left && num[j] > pivot_value){
				--j;
			}

			if(j <= i){
				return i;
			}

			std::swap(num[i], num[j]);
			++i;
			--j;
		}

		return i;
	}

	void Run(int num[], int n) {
		Sort(num, 0, n - 1);
	}

	bool IsSorted(int num[], int n){
		if(n == 1){
			return true;
		}

		for(int i = 1; i < n; ++i){
			if(num[i] < num[i-1]){
				return false;
			}
		}

		return true;
	}

	void Print(int num[], int n){
		for(int i = 0; i < n; ++i){
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}

	virtual void Test(){
		srand(12345);
		int test_count = 10;
		int max_array_size = 10;
		for(int i = 0; i < test_count; ++i){
			for(int j = 1; j <= max_array_size; ++j){
				int array_size = j;
				int* a = new int[array_size];

				for(int k = 0; k < array_size; ++k){
					a[k] = rand() % array_size;
				}

				std::cout << "Before sort: ";
				Print(a, array_size);
				Run(a, array_size);
				std::cout << "After sort: ";
				Print(a, array_size);
				assert(IsSorted(a, array_size));

				delete a;
			}
		}
	}
};


