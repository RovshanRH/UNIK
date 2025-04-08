#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class minheap {
public:
	void heapify_down(vector<int>& heap, int size, int i) { // Создание кучи "снизу"
		int head = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < size && heap[left] < heap[head]) {
			head = left;
		}

		if (right < size && heap[right] < heap[head]) {
			head = right;
		}
		if (head != i) {
			swap(heap[head], heap[i]);
			heapify_down(heap, size, head);
		}
	}

	void heapify_up(vector<int>& heap, int i) { // Создание кучи "сверху"
		int parent = (i - 1) / 2;

		if (i > 0 && heap[parent] > heap[i]) {
			swap(heap[parent], heap[i]);
			heapify_up(heap, parent);
		}
	}



	minheap() : heap(vector<int>{}), size(0) {}; // Конструктор по умолчанию

	minheap(vector<int> arr, int n) { // Конструктор
		this->heap = arr;
		this->size = n;

		for (int i = (size - 1) / 2; i >= 0; i--) {
			heapify_down(heap, size, i);
		}
	}

	void insert(int value) {
		heap.push_back(value);
		size++;
		heapify_up(heap, size - 1);
	}

	void mindelete() {
		heap[0] = heap[size - 1];
		heap.pop_back();
		size--;

		if (size > 0) {
			heapify_down(heap, size, 0);
		}
	}

	int summzatrat() {
		this->heap = heap;
		size = heap.size();
		int summ{};
		int temp{};

		while (size > 1) { 
			summ = heap[0];
			mindelete();
			summ = summ + heap[0];
			temp += summ;
			mindelete();
			insert(summ);
		}
		return temp;
	}

	void printheap() {
		for (int value : heap) {
			cout << value << " ";
		}
		cout << endl;
	}

private:
	int size;
	vector<int> heap;
};

int main() {
	vector<int> test1{ 5,4,2,8 };
	vector<int> test2{ 1,2,3,4 };
	minheap heap1(test1, test1.size());
	minheap heap2(test2, test2.size());
	heap1.printheap();
	heap2.printheap();
	cout << heap1.summzatrat();
	cout << endl;
	cout << heap2.summzatrat();
}