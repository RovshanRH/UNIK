#include <iostream>
#include <vector>

using namespace std;

bool isHeap(vector<int> tree) {
	int n = tree.size();
	if (tree.empty() || n == 1) {
		return false;
	}
	for (unsigned int i = 1; i < n; i++) {
		if ((tree[i] > tree[i - 1] || tree[i] < tree[i - 1]) && ((tree[0] == *max_element(tree.begin(), tree.end()) || (tree[0] == *min_element(tree.begin(), tree.end()))))) {
			return true;
		}
	}
	return false;
	
}

int main() {
	vector<int> test1{0,1,2,3,4,5};
	vector<int> test2{ 8,3,10,1,6,4 };
	cout << boolalpha;
	cout << isHeap(test1);
	cout << endl;
	cout << isHeap(test2);
	
}