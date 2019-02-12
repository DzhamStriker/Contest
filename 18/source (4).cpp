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
        for (int j = 0; j < v.size() - 1; j++) {
            sortmax(v.begin(), v.end() - j);
        }
        int i = 0;
        for (; i < v.size() - 1; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << v[i];
    }
}