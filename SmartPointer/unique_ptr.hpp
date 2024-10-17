namespace SmartPointer
{

template<class T>
class unique_ptr
{
public:
    unique_ptr() = default;
    unique_ptr(const unique_ptr<T>& up) = delete;
    unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;
    unique_ptr(T* ptr) :_ptr(ptr) {}
    ~unique_ptr() { delete _ptr; }

    T& operator*() { return *_ptr; }
    T* operator->() { return return _ptr; }
    T& operator[](size_t pos) { return _ptr[pos]; }
    
private:
    T* _ptr;
};

}  // end of namespace SmartPointer