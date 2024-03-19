#include "my_string.hpp"

namespace my_tiny_stl 
{
    //string::string()
    //    : _str(new char[1])
    //{
    //    _str[0] = '\0';
    //}

    //string::string(const char* str)
    //    : _str(new char[strlen(str) + 1])
    //{
    //    strcpy(_str, str);  // strcpy 拷\0
    //}

    string::string(const char* str)  // 缺省参数在声明给过了
        : _str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
    }

    string::string(const string& s)
        : _str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }

    string::~string()
    {
        delete[] _str;
        _str = nullptr;
    }

    size_t string::size()
    {
        return strlen(_str);
    }

    const char* string::c_str()
    {
        return _str;
    }

    char& string::operator[](size_t i)
    {
        return _str[i];
    }

    string& string::operator=(const string& s)
    {
        //if (s != *this) // 错误
        if (this != &s)
        {
            char* tmp = new char[strlen(s._str) + 1];
            strcpy(tmp, s._str);
            delete[] _str;  // 构造函数都是在堆上申请空间
            _str = tmp;
        }

        return *this;
    }

}  // end of namespace my_tiny_stl 
