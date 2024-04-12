#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class K, class V>
struct HashNode {
    K key;
    V value;
    HashNode* next;

    HashNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
};

template<class K, class V>
class HashMap {
public:
    HashMap(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity, nullptr);
    }

    void insert(const K& key, const V& value);
    V find(const K& key);
    void remove(const K& key);
    int getSize();

private:
    vector<HashNode<K, V>*> table;
    int capacity;
    int size;

    // 哈希函数
    int hashFunction(const K& key) {
        // 这里简单地使用取模运算作为哈希函数
        return hash<K>()(key) % capacity;
    }
};