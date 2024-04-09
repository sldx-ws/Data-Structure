#include "hashMap.hpp"

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key);
    HashNode<K, V>* newNode = new HashNode<K, V>(key, value);

    // 空，直接插入
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        // 非空
        HashNode<K, V>* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

template<typename K, typename V>
V HashMap<K, V>::find(const K& key) {
    int index = hashFunction(key);
    HashNode<K, V>* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    // 如果没有找到，则返回默认值
    return V();
}

template<typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    int index = hashFunction(key);
    HashNode<K, V>* current = table[index];
    HashNode<K, V>* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            // 如果要删除的节点是链表的第一个节点
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            --size;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<typename K, typename V>
int HashMap<K, V>::getSize() {
    return size;
}

template class HashMap<string, int>;