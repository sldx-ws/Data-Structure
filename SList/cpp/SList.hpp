#pragma once
#include <iostream>
using namespace std;



template <class T>
class SList
{
private:
    class SListNode;  // 声明

public:
    SList();
    ~SList();
    void push_back(T x);
    void pop_back();
    void push_front(T x);
    void pop_front();
    SListNode* find(T x);
    void insert(T findNum, T newNum); // 某个节点之后插入
    void erase(T x);

    void print();
private:
    class SListNode 
    {
    public:
        SListNode(T x = 0);

        // 如果设成私有，外部类访问不到
        T _data;
        SListNode* _next;
    };

    SListNode* _head;
};
