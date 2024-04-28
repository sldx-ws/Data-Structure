#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace my_tiny_stl {

template <size_t N>
class bitset {
public:
    bitset();
    void set(size_t x);
    void reset(size_t x);
    bool test(size_t x);
private:
    vector<char> _bits;
};

template <size_t N>
class twobitset {
public:
    void set(size_t x);
    void PirntOnce();

private:
    bitset<N> _bs1;
    bitset<N> _bs2;
};

} // end of namespace my_tiny_stl