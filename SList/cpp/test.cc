#include "SList.hpp"

void test()
{
    SList<int> sl;

    cout << "尾插：";
    sl.push_back(1);
    sl.push_back(2);
    sl.push_back(3);
    sl.push_back(4);
    sl.push_back(5);
    sl.print();

    cout << "尾删：";
    sl.pop_back();
    sl.pop_back();
    sl.print();

    cout << "头插：";
    sl.push_front(-1);
    sl.push_front(-2);
    sl.push_front(-3);
    sl.push_front(-4);
    sl.print();

    cout << "头删：";
    sl.pop_front();
    sl.pop_front();
    sl.print();

    cout << "在3后面插入33：";
    sl.insert(3, 33); 
    sl.print();

    cout << "删除2：";
    sl.erase(2);
    sl.print();
}

int main()
{
    test();

    return 0;
}
