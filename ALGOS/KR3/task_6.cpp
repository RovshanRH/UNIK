#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int priority;
	int data;
	Node* next;

	Node(int number, int value) : priority(number), data(value), next(nullptr) {};

	void insert(Node*& head, int number, int value) {
		Node* newNode = new Node(number, value);

		if (head == nullptr) { // Если список пуст
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != nullptr) { // Идем до последнего узла
			current = current->next;
		}
		current->next = newNode;
	}

	vector<int> extract_minimum(Node*& head) {return { head->priority, head->data };}

	vector<int> extract_maximum(Node*& head) {
		Node* current = head;
		while (current->next != nullptr) {
			
			current = current->next;

			if (current->next == nullptr) {
				return { current->priority, current->data };
			}
			
		}

		return { current->priority, current->data };
	}
	
	void display(Node* head) {
		if (head == nullptr) {
			cout << endl; // Конец списка, перевод строки
			return;
		}
		
		cout << "[ " << head->priority << " , " << head->data << " ]";
		if (head->next != nullptr) {
			cout << " -> ";
		}
		display(head->next);
		
	}
};

int main() {
	Node node(0, 0);
	Node* head = nullptr;
	node.insert(head, -1000, 1);
	node.insert(head, 0, 1);
	node.insert(head, -1, 1);
	node.insert(head, 2, 2);
	node.insert(head, 3, 3);
	node.insert(head, 4, 5);
	node.insert(head, 1000, 5);
	cout << "[ " << "priority" << " , " << "data" << " ]\n\n";
	node.display(head);
	cout << node.extract_minimum(head)[0] << " " << node.extract_minimum(head)[1] << endl;
	cout << node.extract_maximum(head)[0] << " " << node.extract_maximum(head)[1];

	cout << "\n\n";
	Node onenode(0, 0);
	Node* onehead = nullptr;
	onenode.insert(onehead, 100, 10);
	node.display(onehead);
	cout << node.extract_minimum(onehead)[0] << " " << node.extract_minimum(onehead)[1] << endl;
	cout << node.extract_maximum(onehead)[0] << " " << node.extract_maximum(onehead)[1];
}