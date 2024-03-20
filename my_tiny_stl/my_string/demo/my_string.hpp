#pragma once 
#include <iostream>
#include <cstring>
using namespace std;

namespace my_tiny_stl
{
class string 
{
public:
    //string();
    //string(const char* str);
    string(const char* str = "");
    string(const string& s);
    ~string();
    size_t size();
    const char* c_str() const;

    char& operator[](size_t i);
    string& operator=(const string& s);
        
private:
    char* _str;
};

}  // end of namespace my_tiny_stl
