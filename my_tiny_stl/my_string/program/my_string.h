#pragma once 
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

namespace my_tiny_stl
{
class string 
{
public:
    typedef char* iterator;

    string(const char* str = "");
    string(const string& s);
    ~string();

    size_t size() const;
    size_t capacity() const;
    const char& operator[](size_t i) const;
    const char* c_str() const;

    char& operator[](size_t i);
    string& operator+=(char ch);
    string& operator=(const string& s);
        
    iterator begin();
    iterator end();

    void push_back(char ch);
    void append(const char* str);
    
    void resize(size_t n, char ch = '\0');
    void reserve(size_t n);

    string& insert(size_t pos, char ch);
    string& insert(size_t pos, const char* str);
    void erase(size_t pos, size_t len = npos);
    size_t find(char ch, size_t pos = 0);
    size_t find(const char* str, size_t pos = 0);

    string& operator+=(const char* str); // +=字符串

    bool operator<(const string& s);
    bool operator<=(const string& s);
    bool operator>(const string& s);
    bool operator>=(const string& s);
    bool operator==(const string& s);
    bool operator!=(const string& s);
private:
    char* _str;
    size_t _size;
    size_t _capacity;

    static const size_t npos;
};

istream& operator>>(istream& in, string& s) {}
ostream& operator<<(ostream& os, const string& s);
}  // end of namespace my_tiny_stl
