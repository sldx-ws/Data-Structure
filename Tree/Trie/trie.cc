#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode() {
        _isEndOfWord = false;
    }

    unordered_map<char, TrieNode*> _child;
    bool _isEndOfWord;
};

class Trie {
public:
    Trie() {
        _root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = _root;
        for (auto& ch : word) {
            if (cur->_child.find(ch) == cur->_child.end())
                cur->_child[ch] = new TrieNode();

            cur = cur->_child[ch];
        }
        cur->_isEndOfWord = true;
    }

    // 检查一个单词是否在 Trie 中
    bool search(string word) {
        TrieNode* cur = _root;
        for (auto& ch : word) {
            if (cur->_child.find(ch) == cur->_child.end()) 
                return false;

            cur = cur->_child[ch];
        }
        return cur->_isEndOfWord;
    }

    // 检查一个前缀是否在 Trie 中
    bool startsWith(string prefix) {
        TrieNode* cur = _root;
        for (auto& ch : prefix) {
            if (cur->_child.find(ch) == cur->_child.end()) 
                return false;

            cur = cur->_child[ch];
        }
        return true;
    }

private:
    TrieNode* _root;
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