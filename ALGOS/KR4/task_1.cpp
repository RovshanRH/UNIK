#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (unsigned i{}; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {}
};

class Trie {
private:
    TrieNode* root;
public:

    Trie() { root = new TrieNode(); }

    void insertword(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    int countWords(TrieNode* node) {
        if (node == nullptr) { return 0;}
        int count = 0;
        if (node->isEndOfWord) { count++; }

        for (int i{}; i < 26; i++) {
            count += countWords(node->children[i]);
        }

        return count;
   }

    int count(const char& symb) {
        TrieNode* node = root;
        int index = symb - 'a';
        if (node->children[index] == nullptr) {
            return 0;
        }
        node = node->children[index];
        return countWords(node);
    }

    // удаление слова
    /*void deleteword(const string& word) {
        TrieNode* node = root;
        if (root == nullptr) {
            cout << "Бор пустой";
        }
        if (search(word) == false) {
            cout << "Данное слово отсутсвует в Боре";
        }
        for (char ch : word) {
            int index = ch - 'a';
            TrieNode* temp = node->children[index];
            delete temp;
        }
    }*/

    void printTrie() {
        string currentWord;
        printTrieHelper(root, currentWord);
    }

    void printTrieHelper(TrieNode* node, string& currentWord) {
        if (node == nullptr) return;

        if (node->isEndOfWord) {
            cout << currentWord << endl;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                currentWord.push_back('a' + i);
                printTrieHelper(node->children[i], currentWord);
                currentWord.pop_back();  // backtrack
            }
        }
    }

    ~Trie() {}

};

int main() {
    Trie trietree;
    trietree.insertword("hello");
    trietree.insertword("hi");
    trietree.insertword("happy");
    std::cout << std::boolalpha;
    cout << trietree.search("hi") << endl;
    cout << trietree.count('h') << endl;
    //trietree.deleteword("hi");
    trietree.printTrie();
}