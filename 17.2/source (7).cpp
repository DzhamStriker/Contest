#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using iter = std::vector<int>::iterator;

iter merges(iter b1, iter e1, iter b2, iter e2, iter b) {
    while (b1 != e1 && b2 != e2) {
        if (*b1 < *b2) {
            *b = *b1;
            b++;
            b1++;
        } else {
            *b = *b2;
            b++;
            b2++;
        }
    }
    while (b1 != e1) {
        *b = *b1;
        b++;
        b1++;
    }
    while (b2 != e2) {
        *b = *b2;
        b++;
        b2++;
    }
    return b;
}

int main() {
    int a, b;
    std::vector<int> v1, v2;
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        std::cin >> b;
        v1.push_back(b);
    }
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        std::cin >> b;
        v2.push_back(b);
    }
    std::vector<int> v3;
    v3.resize(v1.size() + v2.size());
    merges(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    int i = 0;
    if (v3.size() != 0) {
        for (i = 0; i < v3.size() - 1; i++) {
            std::cout << v3[i] << " ";
        }
        std::cout << v3[i];
    }
}