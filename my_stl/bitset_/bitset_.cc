#include "bitset_.hpp"

namespace my_tiny_stl {
    
template<size_t N>
bitset<N>::bitset() {
    //_bits.resize(N / 8 + 1, 0);
    _bits.resize((N >> 3) + 1, 0);
}

template<size_t N>
void bitset<N>::set(size_t x) {
    size_t index = x >> 3;
    size_t pos = x % 8;

    _bits[index] |= (1 << pos);
}

template<size_t N>
void bitset<N>::reset(size_t x) {
    size_t index = x >> 3;
    size_t pos = x % 8;

    _bits[index] &= (~(1 << pos));
}

template<size_t N>
bool bitset<N>::test(size_t x) {
    size_t index = x >> 3;
    size_t pos = x % 8;

    return _bits[index] & (1 << pos);
}

template<size_t N>
void twobitset<N>::set(size_t x) {
    if (!_bs1.test(x) && !_bs2.test(x)) {  // 00
        _bs2.set(x); // 01
    } else if (!_bs1.test(x) && _bs2.test(x)) {  // 01
        _bs1.set(x); 
        _bs2.reset(x); // 10
    }
}

template<size_t N>
void twobitset<N>::PirntOnce() {
    for (size_t i = 0; i < N; ++i) {
        if (!_bs1.test(i) && _bs2.test(i))
            cout << i << endl;
    }
    cout << endl;
}

template class bitset<0xffffffff>;
template class bitset<100>;
template class twobitset<100>;

}  // end of namesapce my_tiny_stl 