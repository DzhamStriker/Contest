#include <iostream>
#include <list>
#include <vector>

template <typename It, typename Out>
Out reverse_copy(It first, It last, Out out) {
    auto it = last;
    while (it != first) {
        --it;
        *out = *it;
        ++out;
    }
    return out;
}