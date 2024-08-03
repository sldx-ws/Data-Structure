#include "my_string.h"

namespace my_tiny_stl 
{
const size_t string::npos = -1;

string::string(const char* str)  // 缺省参数在声明给过了
{
    _size = strlen(str);
    _capacity = _size;
    _str = new char[strlen(str) + 1];  // 多一个给 '\0'
    strcpy(_str, str);
}

string::string(const string& s)
    : _size(s._size)
    , _capacity(s._capacity)
{
    _str = new char[_capacity + 1];
    strcpy(_str, s._str);
}

string::~string()
{
    delete[] _str;
    _str = nullptr;
    _size = 0;
    _capacity = 0;
}

size_t string::size() const
{
    return _size;
}

size_t string::capacity() const

{
    return _capacity;
}

const char* string::c_str() const
{
    return _str;
}

char& string::operator[](size_t i)
{
    assert(i < _size);

    return _str[i];
}

const char& string::operator[](size_t i) const
{
    assert(i < _size);
    
    return _str[i];
}

istream& operator>>(istream& in, string& s)
{
    
}

ostream& operator<<(ostream& out, const string& s)
{
    // 这种方法不需要定义为友元函数
    for (size_t i = 0; i < s.size(); ++i)  
    {
        out << s[i];
    }

    return out;
}

string& string::operator=(const string& s)
{
    if (this != &s)
    {
        delete[] _str;

        _size = s._size;
        _capacity = s._capacity;

        _str = new char[_capacity + 1];
        strcpy(_str, s._str);
    }

    return *this;
}

string::iterator string::begin()
{
    return _str;
}

string::iterator string::end()
{
    return _str + _size;
}

void string::push_back(char ch)
{
    if (_size == _capacity)
    {
        size_t newCapacity = _capacity == 0 ? 2 : _capacity* 1.5;
        reserve(newCapacity);
    }

    _str[_size++] = ch;
    _str[_size] = '\0';
}

void string::append(const char* str)
{
    size_t len = strlen(str);
    if (_size + len > _capacity)
    {
        size_t newCapacity = _size + len;
        reserve(newCapacity);
    }

    strcpy(_str + _size, str);
    _size += len;
}

void string::resize(size_t n, char ch)
{
    if (n < _size)
    {
        _str[n] = '\0';
        _size = n;
    }
    else
    {
        if (n > _capacity)
        {
            reserve(n);
        }

        for (size_t i = _size; i < n; ++i)
        {
            _str[i] = ch;
        }

        _size = n;
        _str[_size] = '\0';
    }
}

void string::reserve(size_t n)
{
    if (n > _capacity)
    {
        char* newStr = new char[n + 1];
        strcpy(newStr, _str);
        delete[] _str;
        _str = newStr;
        _capacity = n;
    }
}

string& string::operator+=(char ch)
{
    push_back(ch);
    
    return *this;
}

string& string::operator+=(const char* str)
{
    append(str);
    
    return *this;
}

string& string::insert(size_t pos, char ch)
{
    assert(pos < _size);

    if (_size == _capacity)
    {
        size_t newCapacity = _capacity == 0 ? 2 : _capacity * 1.5;
        reserve(newCapacity);
    }

    int endi = _size;
    while (endi >= (int)pos)
    {
        _str[endi + 1]= _str[endi];
        --endi;
    }

    _str[pos] = ch;
    ++_size;

    return *this;
}

void string::erase(size_t pos, size_t len)
{
    if (len >= _size - pos)
    {
        _str[pos] = '\0';
        _size = pos;
    }
    else
    {
        size_t i = pos + len;
        for (size_t i = pos + len; i <= _size; ++i)
        {
            _str[i - len] = _str[i];           
        }

        _size -= len;
    }
}

string& string::insert(size_t pos, const char* str)
{
    assert(pos <= _size); 

    size_t len = strlen(str);
    if (_size + len > _capacity)
    {
        size_t newCapacity = _size + len;
        reserve(newCapacity);
    }

    int endi = _size - 1; 
    while (endi >= static_cast<int>(pos))
    {
        _str[endi + len] = _str[endi];
        --endi;
    }

    strncpy(_str + pos, str, len);
    _size += len;

    return *this;
}
}  // end of namespace my_tiny_stl 
