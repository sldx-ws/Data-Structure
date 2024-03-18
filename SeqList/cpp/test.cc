#include "SeqList.hpp"

void test()
{
    SeqList<int> s;

    cout << "尾插：";
    s.push_back(1); 
    s.push_back(2); 
    s.push_back(3); 
    s.push_back(4); 
    s.push_back(5); 
    s.print();

    cout << "尾删：";
    s.pop_back();
    s.pop_back();
    s.print();

    cout << "头插：";
    s.push_front(-1);
    s.push_front(-2);
    s.print();

    cout << "头删：";
    s.pop_front();
    s.pop_front();
    s.print();

    cout << "下标3插入99：";
    s.insert(3, 99);
    s.print();

    cout << "删除下标为2的元素：";
    s.erase(2);
    s.print();

    cout << "将元素1的下标为：";
    int pos = s.find(1);
    cout << pos << endl;
}

int main()
{
    test();

    return 0;
}
