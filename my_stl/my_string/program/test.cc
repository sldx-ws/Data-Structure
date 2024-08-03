#include "my_string.h"

void test01()
{
    my_stl::string s1;
    my_stl::string s2("hello");

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
    my_stl::string s1("hello");
    my_stl::string s2(s1);
    my_stl::string s3;
    s3 = s1;

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;
}

void test03()
{
    my_stl::string s("hello");

    for (my_stl::string::iterator it = s.begin(); it < s.end(); ++it)
    {
        *it += 1;
        cout << *it << " ";
    }
    cout << endl;

    for (auto& ch : s)
    {
        ch -= 1;
        cout << ch << " ";
    }
    cout << endl;
}

void test04()
{
    my_stl::string s;
    
    s.append("hello");
    s.push_back('!');
    cout << s << endl;
    
    s += "world";
    s += '!';
    cout << s << endl;

    s.insert(0, '*');
    cout << s << endl;

    s.insert(0, "^^");
    cout << s << endl;

    s.erase(0, 3);
    cout << s << endl;
}

void test_morden_deep_copy()
{
    // copy constructor
    my_stl::string s1("hello");
    my_stl::string s2 = s1;
    cout << "s1:" << s1 << " " << "s2:" << s2 << endl;
    cout << "s2.capacity:" << s2.capacity() << " " << "s2.size:" << s2.size() << endl;

    // operator=
    // my_stl::string s1("hello");
    // my_stl::string s2;
    // s2 = s1;
    // cout << "capacity: " << s2.capacity() << " " << "size: " << s2.size() << endl;    
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test_morden_deep_copy();

    return 0;
}
