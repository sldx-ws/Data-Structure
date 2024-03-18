#pragma once 
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class SeqList 
{
public:
    SeqList();
    ~SeqList();
    void push_back(T x);
    void pop_back();
    void push_front(T x);
    void pop_front();
    void insert(size_t pos, T x);
    void erase(size_t pos);
    int find(T x);  // 查找返回下标
    void CheckCapacity();

    void print();
private:
    T* _a;
    int _size;
    int _capacity;
};
