#include <iostream>
#include <cstring>
using namespace std;

namespace mystl
{
class string
{
public:
    /*
    string()
        : _str(new char[1])
    {
        _str[0] = '\0';
    }

    string(const char* str)
        : _str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
    }
    */

    // 缺省参数
    string(const char* str = "")
        : _str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
    }

    // 深拷贝
    string(const string& s)
        : _str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }

    ~string()
    {
        delete[] _str;
        _str = nullptr;
    }

    size_t size()
    {
        return strlen(_str);
    }

    string& operator=(const string& s)
    {
        if (this != &s)
        {
            char* tmp = new char[strlen(s._str) + 1];
            strcpy(tmp, s._str);
            delete[] _str;
            _str = tmp;
        }
        
        return *this;
    }

    char& operator[](size_t i)
    {
        return _str[i];
    }

    const char* c_str()
    {
        return _str;
    }

private:
    char* _str;

};

// 测试构造函数
void test_string1()
{
    string s1;
    string s2("hello");

    for (int i = 0; i < s1.size(); ++i)
    {
        cout << s1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < s2.size(); ++i)
    {
        cout << s2[i] << " ";
    }
    cout << endl;
}

// 测试深拷贝
void test_string2()
{
    string s1("hello");
    string s2(s1);

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;

    string s3("world");
    s1 = s3;
    cout << s1.c_str() << endl;
    cout << s3.c_str() << endl;
}

}  // end of namespace ws
