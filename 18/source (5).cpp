#include <iostream>
#include <vector>
#include <algorithm>

using iter = std::vector<int>::iterator;

iter partition(iter begin, iter end, int predicut) {
    while (begin != end) {
        while (predicut > *begin) {
            ++begin;
            if (begin == end) {
                return begin;
            }
        }
        do {
            --end;
            if (begin == end) {
                return begin;
            }
        } while (predicut <= *end);
        std::swap(*begin, *end);
        ++begin;
    }
    return begin;
}

int main() {
    int a, b, pr;
    std::vector<int> v;
    std::cin >> a;
    if (a != 0) {
        for (int i = 0; i < a; i++) {
            std::cin >> b;
            v.push_back(b);
        }
        std::cin >> pr;
        iter end = partition(v.begin(), v.end(), pr);
        int s = end - v.begin();
        std::cout << s << '\n';
        std::cout << a - s;
    } else {
        std::cin >> b;
        std::cout << 0 << '\n';
        std::cout << 0;
    }
}