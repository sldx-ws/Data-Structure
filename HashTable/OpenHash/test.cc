#include "HashTable.hpp"

void TestHashTable()
{
	HashTable<int> ht;
	ht.Insert(4);
	ht.Insert(14);
	ht.Insert(24);
	ht.Insert(5);
	ht.Insert(15);
	ht.Insert(25);
	ht.Insert(6);
	ht.Insert(16);
	ht.Insert(26);

	ht.Erase(14);
	HashNode<int>* ph = ht.Find(14);
	if (ph == nullptr)
		cout << "nullptr" << endl;
}

int main()
{
	TestHashTable();
	
	return 0;
}