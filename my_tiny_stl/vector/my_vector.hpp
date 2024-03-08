#pragma once 


namespace mystl
{

template<class T>
class vector
{
public:
    typedef T* iterator;

private:
    iterator _start;
    iterator _finish;
    iterator _endofstorage;
};

}  // end of namespace mystl