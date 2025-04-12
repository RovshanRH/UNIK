#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxheap {
public:
    // перестройка кучи "снизу"
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
    // перестройка кучи "сверху"
    void heapify_up(vector<int>& heap, int index) {
        int parent = (index - 1) / 2;

        if (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapify_up(heap, parent);
        }
    }

    // конструктор
    maxheap(vector<int>& array, int size) {
        heap = array;
        n = size;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify_down(heap, n, i);
        }
    }
    // конструктор по умолчанию
    maxheap() : heap(vector<int> {}), n(0) {}

    // поиск максимума
    int maxelement() { return heap[0]; }

    // удаление максимума
    void maxdelete() {
        heap[0] = heap[n - 1];
        heap.pop_back();
        n--;

        if (n > 0) {
            heapify_down(heap, n, 0);
        }
    }

    // добавление нового элемента
    void insertelement(int value) {
        heap.push_back(value);
        n++;
        heapify_up(heap, n - 1);
    }

    // вывод в терминале
    void printheap() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }

    void connect(vector<int>& heap2) {
        for (unsigned int i{}; i < heap2.size(); i++) {
            auto it = find(heap.begin(), heap.end(), heap2[i]); // проверка на равные узлы в 2 кучах
            if (it != heap.end()) {
                continue;
            }
            insertelement(heap2[i]);
        }
    }

private:
    vector<int> heap;
    int n;
};

int main() {
    // test
    vector<int> test1{ 2, 5, 10, 20, 30 };
    vector<int> test2{ 1,2, 2, 2, 2, 2,3,4 };
    vector<int> test3{};
    maxheap heap(test1, test1.size());

    /*cout << heap.maxelement() << endl;
    heap.printheap();
    heap.maxdelete();
    heap.printheap();
    heap.insertelement(1);
    heap.insertelement(100);
    heap.printheap();*/
    
    heap.connect(test2);
    heap.printheap();
    heap.connect(test3);
    heap.printheap();

}