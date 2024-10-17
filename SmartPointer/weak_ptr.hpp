namespace SmartPointer
{

template<class T>
class weak_ptr
{
public:
    weak_ptr() = default;
    weak_ptr(const shared_ptr<T>& sp) : _ptr(sp.get()) {}

    weak_ptr<T>& operator=(const shared_ptr<T>& sp)
    {
        _ptr = sp.get();
        return *this;
    }

    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }
    
public:
    T* _ptr = nullptr;
};

}  // end of namespace SmartPointer