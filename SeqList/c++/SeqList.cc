#include "SeqList.hpp"

template <class T>
SeqList<T>::SeqList()
{
    _a = new T[4];
    _size = 0;
    _capacity = 4;
}

template <class T>
SeqList<T>::~SeqList()
{
    delete[] _a;
    _a = nullptr;
    _size = 0;
    _capacity = 0;
}

template <class T>
void SeqList<T>::CheckCapacity()
{
    if (_size >= _capacity)
    {
        _capacity *= 1.5;
        T* tmp = new T[_capacity];
        memcpy(tmp, _a, _size * sizeof(T));
        delete[] _a;
        _a = tmp;
    }
}

template <class T>
void SeqList<T>::push_back(T x)
{
    CheckCapacity();
    _a[_size++] = x;
}

template <class T>
void SeqList<T>::pop_back()
{
    if (_size > 0)
        --_size;
}

template <class T>
void SeqList<T>::push_front(T x)
{
    CheckCapacity();

    int endi = _size - 1;
    while (endi >= 0)
    {
        _a[endi + 1] = _a[endi];
        --endi;
    }

    _a[0] = x;
    ++_size;
}

template <class T>
void SeqList<T>::pop_front()
{
    if (_size > 0)
    {
        int begini = 0;
        while (begini < _size - 1)
        {
            _a[begini] = _a[begini + 1];
            ++begini;
        }

        --_size;
    }
}

template <class T>
void SeqList<T>::insert(size_t pos, T x)
{
    if ((int)pos <= _size)
    {
        CheckCapacity();
        
        int endi = _size;
        while (endi > (int)pos)
        {
            _a[endi] = _a[endi - 1];
            --endi;
        }

        _a[pos] = x;
        ++_size;
    }
}

template <class T>
void SeqList<T>::erase(size_t pos)
{
    if ((int)pos < _size)
    {
        int begini = pos;
        while (begini < _size - 1)
        {
            _a[pos] = _a[pos + 1];
            ++begini;
        }

        --_size;
    }
}

template <class T>
int SeqList<T>::find(T x)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_a[i] == x)
            return i;
    }

    return -1;
}

template <class T>
void SeqList<T>::print()
{
    for (int i = 0 ; i < _size; ++i)
    {
        cout << _a[i] << " ";
    }

    cout << endl;
}

template class SeqList<int>;
