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
    my_tiny_stl::string s1("hello");
    my_tiny_stl::string s2(s1);
    my_tiny_stl::string s3;
    s3 = s1;

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;
}

void test03()
{
    my_tiny_stl::string s("hello");

    for (my_tiny_stl::string::iterator it = s.begin(); it < s.end(); ++it)
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
    my_tiny_stl::string s;
    
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

int main()
{
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}
