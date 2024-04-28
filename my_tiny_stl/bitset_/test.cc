#include "bitset_.hpp"

void test_bitset() {  
    //bitset<100> bs1;
    //bitset<-1> bs2;
    my_tiny_stl::bitset<0xffffffff> bs2; // 2^32

    bs2.set(10);
    bs2.set(10000);
    bs2.set(8888);

    cout << bs2.test(10) << endl;
    cout << bs2.test(10000) << endl;
    cout << bs2.test(8888) << endl;
    cout << bs2.test(8887) << endl;
    cout << bs2.test(9999) << endl << endl;

    bs2.reset(8888);
    bs2.set(8887);

    cout << bs2.test(10) << endl;
    cout << bs2.test(10000) << endl;
    cout << bs2.test(8888) << endl;
    cout << bs2.test(8887) << endl;
    cout << bs2.test(9999) << endl;
}

void test_twobitset() {
    my_tiny_stl::twobitset<100> tbs;
    int a[] = { 3, 5, 6, 7, 8, 9, 33, 55, 67, 3, 3, 3, 5, 9, 33 };

    for (auto e : a)
        tbs.set(e);

    tbs.PirntOnce();
}

int main() {
    //test_bitset();
    test_twobitset();

    return 0;
}