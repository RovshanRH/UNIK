#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> maxheap(vector<int> heap, int n, int head) {
//	while (head > 0) {
//		int parent = (head - 1) / 2;
//		if (heap[head] > heap[parent]) {
//			swap(heap[head], heap[parent]);
//			maxheap(heap, head, parent);
//		} else {
//			break;
//		}
//	}
//	return heap;
//}

void heapify_down(vector<int>& heap, int n, int index) {
    int head = index;
    int left = 2 * index + 1;
	int right = 2 * index + 2;

    if (left < n && heap[left] > heap[head]) {
        head = left;
    }

    if (right < n && heap[right] > heap[head]) {
        head = right;
    }
    
    if (head != index) {
        swap(heap[index], heap[head]);
        heapify_down(heap, n, head); 
    }
}

vector<int> maxheap(vector<int> heap) {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_down(heap, n, i);
    }

    return heap;
}
void printheap(vector<int> heap) {
	for (int value : heap) {
		cout << value << " ";
	}
	cout << endl;
}

int main() {
	vector<int> heap1{ 1, 2, 3, 4, 5 };
	vector<int> heap2{ 2, 5, 10, 20, 30 };
    vector<int> heap3{ 0, 10, 12, 11, 4 };

	/*printheap(maxheap(heap1, 0, heap1.size()-1));
	printheap(maxheap(heap2, 0, heap2.size()-1));*/

    printheap(maxheap(heap1));
    printheap(maxheap(heap2));
    printheap(maxheap(heap3));
}