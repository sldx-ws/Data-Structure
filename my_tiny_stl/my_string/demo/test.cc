#include "my_string.hpp"

void test01()
{
    my_tiny_stl::string s1;
    my_tiny_stl::string s2("hello");

    for (size_t i = 0; i < s1.size(); ++i)
    {
        cout << s1[i] << " "; 
    }
    cout << endl;

    for (size_t i = 0; i < s2.size(); ++i)
    {
        s2[i] += 1;
        cout << s2[i] << " ";
    }
    cout << endl;
}

void test02()
{
    string s1("hello");
    string s2(s1);
    string s3;
    s3 = s1;

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;
}

int main()
{
    //test01();
    test02();

    return 0;
}
