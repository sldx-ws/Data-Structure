#pragma once

#include <iostream>
#include <vector>
using namespace std;

template <class K>
struct HashNode
{
	HashNode(const K& key)
		: _data(key)
	{}
	
	K _data;
	HashNode<K>* _next = nullptr;
};

template <class K>
class HashTable
{
	typedef struct HashNode<K> Node;
public:
	bool Insert(const K& key);	
	bool Erase(const K& key);
	Node* Find(const K& key);

private:
	vector<Node*> _tables;
	size_t _num = 0; // valid data
};

template <class K>
bool HashTable<K>::Insert(const K& key)
{	
	if (_tables.size() == _num)
	{
		vector<Node*> newTables;
		size_t newSize = _tables.size() == 0 ? 10 : 2 * _tables.size();
		newTables.resize(newSize);
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				size_t index = key % newTables.size();
				cur->_next = newTables[index];
				newTables[index] = cur;

				cur = next;
			}

			_tables[i] = nullptr;
		}

		_tables.swap(newTables);
	}

	size_t index = key % _tables.size();
	Node* cur = _tables[index];
	while (cur)
	{
		if (cur->_data == key)
			return false;
		else
			cur = cur->_next;
	}

	Node* newNode = new Node(key);
	newNode->_next = _tables[index];
	_tables[index] = newNode;
	++_num;
	
	return true;
}

template <class K>
bool HashTable<K>::Erase(const K& key)
{
	size_t index = key % _tables.size();

	// double pointer
	Node* prev = nullptr;
	Node* cur = _tables[index];
	while (cur)
	{
		if (cur->_data == key)
		{
			if (prev == nullptr)
				_tables[index] = cur->_next;
			else
				prev->_next = cur->_next;
			
			delete cur;
			return true;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

template <class K>
typename HashTable<K>::Node* HashTable<K>::Find(const K& key)
{
	size_t index = key % _tables.size();
	Node* cur = _tables[index];
	while (cur)
	{
		if (cur->_data == key) 
			return cur;
		else 
			cur = cur->_next;
	}
	
	return nullptr;
}