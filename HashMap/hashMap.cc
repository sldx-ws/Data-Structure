#include "hashMap.hpp"

template<class K, class V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key);
    HashNode<K, V>* newNode = new HashNode<K, V>(key, value);

    // 空，直接插入
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        // 非空
        HashNode<K, V>* cur = table[index];
        while (cur->next != nullptr) 
            cur = cur->next;
        
        cur->next = newNode;
    }
    ++size;
}

template<class K, class V>
V HashMap<K, V>::find(const K& key) {
    int index = hashFunction(key);
    HashNode<K, V>* cur = table[index];
    while (cur != nullptr) {
        if (cur->key == key) 
            return cur->value;
        
        cur = cur->next;
    }
    // 如果没有找到，则返回默认值
    return V();
}

template<class K, class V>
void HashMap<K, V>::remove(const K& key) {
    int index = hashFunction(key);
    HashNode<K, V>* cur = table[index];
    HashNode<K, V>* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            // 如果要删除的节点是链表的第一个节点
            if (prev == nullptr) 
                table[index] = cur->next;
            else 
                prev->next = cur->next;
            
            delete cur;
            --size;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

template<class K, class V>
int HashMap<K, V>::getSize() {
    return size;
}

template class HashMap<string, int>;