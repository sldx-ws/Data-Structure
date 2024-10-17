#include <mutex>

namespace SmartPointer
{

template<class T, class D = default_delete<T>>
class shared_ptr
{
public:
    shared_ptr(T* ptr = nullptr) :_ptr(ptr), _pcount(new int(1)), _pmtx(new mutex) {}
    shared_ptr(const shared_ptr<T>& sp);
    ~shared_ptr() { Release();}
    shared_ptr<T>& operator=(const shared_ptr<T>& sp);
    int use_count() const { return *_pcount; }
    T* get() const { return _ptr; }
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }
    T& operator[](size_t pos) { return _ptr[pos]; }

private: 
    void Release();

private:
    T* _ptr;
    int* _pcount;
    mutex* _pmtx;

    D _del;
};

template <class T, class D = default_delete<T>>
shared_ptr<T, class D = default_delete<T>>::shared_ptr(const shared_ptr<T>& sp)
    :_ptr(sp._ptr)
    , _pcount(sp._pcount)
    , _pmtx(sp._pmtx)
{
    _pmtx->lock();
    ++(*_pcount);
    _pmtx->unlock();
}

template <class T, class D = default_delete<T>>
shared_ptr<T>& shared_ptr<T, class D = default_delete<T>>::operator=(const shared_ptr<T>& sp)
{
    if (_ptr != sp._ptr)
    {
        Release();

        _pcount = sp._pcount;
        _ptr = sp._ptr;
        _pmtx = sp._pmtx;

        _pmtx->lock();
        ++(*_pcount);
        _pmtx->unlock();
    }

    return *this;
}

template <class T, class D = default_delete<T>>
void shared_ptr<T, class D = default_delete<T>>::Release()
{
    bool flag = false;
    _pmtx->lock();
    if (--*_pcount == 0)
    {
        _del(_ptr);

        delete _pcount;
        flag = true;
    }
    _pmtx->unlock();

    if (flag == true) delete _pmtx;
}

}  // end of namespace SmartPointer