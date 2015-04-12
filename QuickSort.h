#include "Common.h"
#include <assert.h>

template<typename T> class MedianSelector {
public:
	MedianSelector() {;}
	int operator()(T num[], int left, int right){
		return (left+right) >> 1;
	}
};

template<typename T> class NormalPartitioner {
public:
	NormalPartitioner() {;}
	int operator()(T num[], int left, int right, T pivot_value){
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
};

template<typename T, class PivotSelector, class Partitioner> class QuickSort {
	PivotSelector pivot_selector_;
	Partitioner partitioner_;

public:
	QuickSort() {;}

	void Sort(T num[], int left, int right){
		if(left < right){
			int pivot_index = pivot_selector_(num, left, right);

			std::swap(num[pivot_index], num[right]);
			int partition_index = partitioner_(num, left, right - 1, num[right]);

			std::swap(num[partition_index], num[right]);
			Sort(num, left, partition_index - 1);
			Sort(num, partition_index + 1, right);
		}
	}

	void Run(T num[], int n) {
		Sort(num, 0, n - 1);
	}
};

class QuickSortTest : public TestCase  {
	virtual void Test(){
		QuickSort<int, MedianSelector<int>, NormalPartitioner<int> > sorter;
//		QuickSort<int> sorter;

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
				sorter.Run(a, array_size);
				std::cout << "After sort: ";
				Print(a, array_size);
				assert(IsSorted(a, array_size));

				delete a;
			}
		}
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
};


