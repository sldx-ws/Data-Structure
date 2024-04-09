#include "hashMap.hpp"

int main() {
    HashMap<string, int> hashTable(10);

    hashTable.insert("apple", 5);
    hashTable.insert("banana", 3);
    hashTable.insert("orange", 7);

    cout << "apple: " << hashTable.find("apple") << endl; // 5
    cout << "grape: " << hashTable.find("grape") << endl; // 0

    hashTable.remove("banana");

    cout << "Size: " << hashTable.getSize() << endl; // 2

    return 0;
}