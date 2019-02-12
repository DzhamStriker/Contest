#include <iostream>
#include <list>
#include <vector>

template <class It>
It rotate_range(It first, It new_first, It last) {
    It next = new_first;
    while (first != next) {
        std::swap(*first++, *next++);
        if (next == last) {
            next = new_first;
        } else if (first == new_first) {
            new_first = next;
        }
    }
    return next;
}