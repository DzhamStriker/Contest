#include <iostream>
#include <vector>
#include <algorithm>

using iter = std::vector<int>::iterator;

iter sortmax(iter begin, iter end) {
    iter maxim = begin;
    while (begin != end) {
        if (*begin > *maxim) {
            maxim = begin;
        }
        begin++;
    }
    std::iter_swap(maxim, end - 1);
    return end;
}

int main() {
    int a, b;
    std::vector<int> v;
    std::cin >> a;
    if (a != 0) {
        for (int i = 0; i < a; i++) {
            std::cin >> b;
            v.push_back(b);
        }
        sortmax(v.begin(), v.end());
        int i = 0;
        for (; i < v.size() - 1; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << v[i];
    }
}