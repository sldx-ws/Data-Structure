#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode() {
        isEndOfWord = false;
    }

    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // 插入
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end())
                current->children[c] = new TrieNode();

            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    // 检查一个单词是否在 Trie 中
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) 
                return false;

            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    // 检查一个前缀是否在 Trie 中
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) 
                return false;

            current = current->children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << (trie.search("apple") ? 'Y' : 'N') << endl;   // Y
    cout << (trie.search("app") ? 'Y' : 'N') << endl;     // N
    cout << (trie.startsWith("app") ? 'Y' : 'N') << endl; // Y

    trie.insert("app");
    cout << (trie.search("app") ? 'Y' : 'N') << endl;     // Y
    return 0;
}