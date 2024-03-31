#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode() {
        isEndOfWord = false;
    }

    unordered_map<char, TrieNode*> child;
    bool isEndOfWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (auto& ch : word) {
            if (cur->child.find(ch) == cur->child.end())
                cur->child[ch] = new TrieNode();

            cur = cur->child[ch];
        }
        cur->isEndOfWord = true;
    }

    // 检查一个单词是否在 Trie 中
    bool search(string word) {
        TrieNode* cur = root;
        for (auto& ch : word) {
            if (cur->child.find(ch) == cur->child.end()) 
                return false;

            cur = cur->child[ch];
        }
        return cur->isEndOfWord;
    }

    // 检查一个前缀是否在 Trie 中
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto& ch : prefix) {
            if (cur->child.find(ch) == cur->child.end()) 
                return false;

            cur = cur->child[ch];
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