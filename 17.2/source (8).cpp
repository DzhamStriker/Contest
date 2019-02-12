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

std::vector<int> premerge(std::vector<int>& v1, std::vector<int>& v2) {
    if (v1.size() != 0) {
        std::vector<int> v3, v4, v5;
        std::vector<int> f1(v1.begin(), v1.begin() + v1.size() / 2);
        std::vector<int> f2(v1.begin() + v1.size() / 2, v1.end());
        v4 = premerge(f1, f2);
        std::vector<int> f3(v2.begin(), v2.begin() + v2.size() / 2);
        std::vector<int> f4(v2.begin() + v2.size() / 2, v2.end());
        v5 = premerge(f3, f4);
        v3.resize(v4.size() + v5.size());
        merges(v4.begin(), v4.end(), v5.begin(), v5.end(), v3.begin());
        return v3;
    } else {
        return v2;
    }
}

int main() {
    int a, b;
    std::vector<int> v1;
    std::cin >> a;
    if (a != 0) {
        for (int i = 0; i < a; i++) {
            std::cin >> b;
            v1.push_back(b);
        }
        std::vector<int> f1(v1.begin(), v1.begin() + v1.size() / 2);
        std::vector<int> f2(v1.begin() + v1.size() / 2, v1.end());
        v1 = premerge(f1, f2);
        int i = 0;
        for (; i < a - 1; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << v1[i];
    }
}