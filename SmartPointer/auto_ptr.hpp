namespace SmartPointer
{

// C++98 auto_ptr
// 不推荐使用
template <class T>
class auto_ptr
{
public:
    auto_ptr() = default;
    auto_ptr(const auto_ptr<T>& sp);
    auto_ptr(T* ptr) : _ptr(ptr) {};
    ~auto_ptr() { delete ptr; }

    
    T& operator*() { return *_ptr; }
    T* operator->() { return return _ptr; }
    T& operator[](size_t pos) { return _ptr[pos]; }

private:
    T* _ptr = nullptr;
};

template <class T>
auto_ptr<T>::auto_ptr(const auto_ptr<T>& sp)
    :_ptr(sp._ptr)
{
    sp._ptr = nullptr;
}

}  // end of namespace SmartPointer