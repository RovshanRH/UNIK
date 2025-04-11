#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:

	Heap() : heap(vector<int>{}), size(0) {};
	Heap(vector<int> arr, int n) : heap(arr), size(n) {};

	bool isSorted(const vector<int>& arr) {
		if (arr.empty() || size == 1) {
			return true;
		}

		for (size_t i = 1; i < size; i++) {
			if (arr[i] > arr[i - 1]) {
				return false;
			}
		}

		return true;
	}

	void heapify_down(int i, bool is_max) {
		int head = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (is_max) {
			if (left < size && heap[left] > heap[head]) {
				head = left;
			}
			if (right < size && heap[right] > heap[head]) {
				head = right;
			}
		}
		else {
			if (left < size && heap[left] < heap[head]) {
				head = left;
			}
			if (right < size && heap[right] < heap[head]) {
				head = right;
			}
		}
		if (head != i) {
			swap(heap[head], heap[i]);
			heapify_down(head, is_max);
		}
	}

	void createHeap() {
		bool is_max = isSorted(heap);

		for (int i = (size / 2) - 1; i >= 0; i--) {
			heapify_down(i, is_max);
		}
	}

	void HeapSort() {
		createHeap();
		int originalSize = size;
		bool is_max = isSorted(heap);
		
		for (int i = size - 1; i > 0; i--) {
			swap(heap[0], heap[i]);
			size--;
			heapify_down(0, is_max);
		}
		size = originalSize;
	}


	void printheap() {
		for (int value : heap) {
			cout << value << " ";
		}
		cout << endl;
	}

protected:
	vector<int> heap;
	int size;
};

int main() {
	// maxheap
	vector<int> test1{ 5,4,3,2,1 };
	Heap heap1(test1, test1.size());
	heap1.HeapSort();
	heap1.printheap();
	//minheap
	vector<int> test2{ 1,2,3,4,5 };
	Heap heap2(test2, test2.size());
	heap2.HeapSort();
	heap2.printheap();
	// maxheap
	vector<int> test3{ 12,11,10,9,8,7,6, 5,4,3,2,1 };
	Heap heap3(test3, test3.size());
	heap3.HeapSort();
	heap3.printheap();
}