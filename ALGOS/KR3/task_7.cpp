#include <iostream>
#include <vector>
#include <string>
#include "windows.h"
#include <clocale>
#include <codecvt>
#include <locale>


using namespace std;

struct Task {
	char priority;
	string name;
	Task* next;

	Task() : priority(), name(""), next(nullptr) {};
	Task(char number, string text) : priority(number), name(text), next(nullptr) {};

	void insert(Task*& head, char priority, string name) {
		Task* newtask = new Task(priority, name);

		if (head == nullptr) {
			head = newtask;
			return;
		}
		Task* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newtask;
	}

	Task* delete_maximum(Task*& head) {
		if (head == nullptr) {
			return nullptr;
		}

		if (head->next == nullptr) {
			delete head;
			return nullptr;
		}
		Task* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}

		Task* temp = current->next;
		current->next = nullptr;
		delete temp;

		return head;
	}


	void printmealist(Task*& head) {
		if (head == nullptr) {
			cout << "������ ����� ����!\n";
			return;
		}

		Task* current = head;
		while (current != nullptr)
		{
			cout << "(" << current->priority << ") " + current->name ;
			if (current->next != nullptr) {
				cout << "\n";
			}
			current = current->next;
		}
		cout << endl;

		
	}

	string extract_maximum_name(Task*& head) {
		Task* current = head;
		while (current->next != nullptr) {

			current = current->next;

			if (current->next == nullptr) {
				return current->name;
			}

		}
		
		return current->name;
	}

	Task* edit(Task*& head, char priority, string str, string newstr) {
		Task* current = head;
		while (current != nullptr && (current->priority != priority || current->name != str)) {
			current = current->next;
		}

		if (current != nullptr) {
			current->name = newstr;
		}

		return head;
	}

};

vector<vector<string>> help
{
	{"exit", " - ����� �� �������"},
	{"print", " - ����� �� ����� ������"},
	{"text", " - �������� ������"},
	{"delete", " - �������� ��� ����������� ������ � ������� ������ �� ������" },
	{"edit", " - ���������� �������� ������"},
	{"help", " - ����� �� ����� ������ ��������� ������ � �� ��������" },
	{"textmore", " - ����������� ��������� �����"},
	{"textstop", " - ������������ ��������� �����"}
};

void helpinterminal() {
	cout << "\n������ ������\n\n";
	for (unsigned int i{}; i < help.size(); i++) {
		for (unsigned int j{}; j < 2; j++) {
			cout << help[i][j];
		}
		cout << endl;
	}
};


int main() { 

	// ������������� ������� �������� UTF-8 ��� �������
	SetConsoleCP(1251);         // ��������� ��������� �����
	SetConsoleOutputCP(1251);   // ��������� ��������� ������

	setlocale(LC_ALL, "Russian");

	char priority{};
	string name{};

	Task task;
	Task* head = nullptr;
	cout << "������� 'help' ��� ������ �� ����� ������ ��������� ������ � �� ��������\n";
	while (true) {

		string input;
		getline(cin, input);
		if (input == help[0][0]) {
			break;
		}
		if (input == help[1][0]) {
			task.printmealist(head);
		}
		if (input == help[2][0]) {
			cin >> priority;
			getline(cin, name);

			task.insert(head, priority, name);
		}
		if (input == help[6][0]) {
			cout << "����� ������������ ����� �����. ������� ����� ������� ���������� - 'textstop' ��� ������\n";
			bool neverstoppinginput = true;

			while (neverstoppinginput) {
				cin >> priority;
				getline(cin, name);

				if (name == " textstop") {
					neverstoppinginput = false;
					cout << "����� ������������ ����� ����� ��������\n";
				}
				else {
					task.insert(head, priority, name);
				}
			}
		}
		
		if (input == help[3][0]) {
			
			if (head != nullptr) {
				string taskName = task.extract_maximum_name(head);
				if (!taskName.empty()) {
					cout << "������ \"" + taskName + " \" ���������!\n";
					head = task.delete_maximum(head);
					task.printmealist(head);
				}
			}
			else {
				task.printmealist(head);
			}
		}

		if (input == help[4][0]) {
			string newname;
			cout << "�������� ��������� � ������ ��� ������: ";
			cin >> priority;
			getline(cin, name);
			cout << "\n�������� ����� ���: ";
			getline(cin, newname);
			head = task.edit(head, priority, name, newname);
			task.printmealist(head);
		}

		if (input == help[5][0]) {
			helpinterminal();
		}
		
	}
	while (head != nullptr) {
		Task* temp = head;
		head = head->next;
		delete temp;
	}

}