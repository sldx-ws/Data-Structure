#pragma once

#include <iostream>
#include <vector>
using namespace std;

enum State
{
	EMPTY, 
	EXIST,
	DELETE,
};

template <class K>
struct HashData
{
	K _data;
	State _state = EMPTY;
};

template <class K>
class HashTable
{
	typedef struct HashData<K> HashData;
public:
	bool Insert(const K& key);	
	bool Erase(const K& key);
	HashData* Find(const K& key);

private:
	vector<HashData> _tables;
	size_t _num = 0; // valid data
};

template <class K>
bool HashTable<K>::Insert(const K& key)
{
	if (_tables.size() == 0 || _num * 0.1 / _tables.size() >= 0.7)
	{
		HashTable<K> newHt;
		size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
		newHt._tables.resize(newSize);
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			if (_tables[i]._state == EXIST)
				newHt.Insert(_tables[i]._data);
		}

		_tables.swap(newHt._tables); // 现代写法
	}
	
	size_t index = key % _tables.size();
	int i = 1;
	while (_tables[index]._state == EXIST)
	{
		if (_tables[index]._data == key) return false;
		
		// index = (index + 1) % _tables.size(); // 线性探测
		index = (index + i*i) % _tables.size(); // 二次探测
		++i;
	}
	
	_tables[index]._data = key;
	_tables[index]._state = EXIST;
	++_num;
	
	return true;
}

template <class K>
bool HashTable<K>::Erase(const K& key)
{
	HashData* ret = Find(key);
	if (ret)
	{
		ret->_state = DELETE;
		--_num;
		return true;
	}
	else
	{
		return false;
	}
}

template <class K>
typename HashTable<K>::HashData* HashTable<K>::Find(const K& key)
{
	size_t index = key % _tables.size();
	int i = 1;
	while (_tables[index]._state != EMPTY)
	{
		if (_tables[index]._data == key)
		{
			if (_tables[index]._state == EXIST)
				return &_tables[index];
			else if (_tables[index]._state == DELETE)
				return nullptr;
		}
		
		// index = (index + 1) % _tables.size(); // 线性探测
		index = (index + i*i) % _tables.size(); // 二次探测
		++i;
	}
	
	return nullptr;
}