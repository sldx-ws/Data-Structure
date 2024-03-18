#include "SList.hpp"

template <class T>
SList<T>::SListNode::SListNode(T x)
{
    _data = x;
    _next = nullptr;
}

template <class T>
SList<T>::SList()
{
    _head = nullptr;
}

template <class T>
SList<T>::~SList()
{

}

template <class T>
void SList<T>::push_back(T x)
{
    SListNode* newNode = new SListNode(x);
    
    if (_head == nullptr)
    {
        _head = newNode;
    }
    else 
    {
        SListNode* tail = _head;
        while (tail->_next)
        {
            tail = tail->_next;
        }

        tail->_next = newNode;
    }
}

template <class T>
void SList<T>::pop_back()
{
    if (_head != nullptr)
    {
        SListNode* prev = nullptr;
        SListNode* cur = _head;

        while (cur->_next)
        {
            prev = cur;
            cur = cur->_next;        
        }
        
        delete cur;

        if (prev == nullptr)
            _head = nullptr;
        else 
            prev->_next = nullptr;
    }
}

template <class T>
void SList<T>::push_front(T x)
{
    SListNode* newNode = new SListNode(x);
    
    newNode->_next = _head;
    _head = newNode;
}

template <class T>
void SList<T>::pop_front()
{
    if (_head != nullptr)
    {
        SListNode* tmp = _head;
        _head = tmp->_next;
        delete tmp;
    }
}

template <class T>
// typename 关键字用于告诉编译器 SList<T>::SListNode* 是一个类型名。
// 在模板类的成员函数外部定义时，需要使用 typename 来指明该成员函数返回的类型是一个嵌套类型。
typename SList<T>::SListNode* SList<T>::find(T x)  // 注意写法
{
    SListNode* cur = _head;
    while (cur)
    {
        if (cur->_data == x)
            return cur;

        cur = cur->_next;
    }

    return nullptr;
}

template <class T>
void SList<T>::insert(T findNum, T newNum)
{
    SListNode* pos = find(findNum);

    if (pos != nullptr)
    {
        SListNode* newNode = new SListNode(newNum);

        newNode->_next = pos->_next;
        pos->_next = newNode;
    }
}

template <class T>
void SList<T>::erase(T x)
{
    SListNode* pos = find(x);

    if (pos != nullptr)
    {
        if (_head == pos)  // 删头节点
        {
            _head = pos->_next;
            delete pos;
        }
        else 
        {
            SListNode* prev = _head;
            while (prev->_next != pos)
            {
                prev = prev->_next;
            }

            if (prev != nullptr)
            {
                prev->_next = pos->_next;
                delete pos;
            }
        }

    }
}

template <class T>
void SList<T>::print()
{
    SListNode* cur = _head;
    while (cur)
    {
        cout << cur->_data << "->";
        cur = cur->_next;
    }

    cout << "nullptr" << endl;
}

template class SList<int>;
