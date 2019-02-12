#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int a, b;
    std::vector<int> v, r;
    std::set<int> s;
    std::cin >> a;
    if (a != 0) {
        for (int i = 0; i < a; i++) {
            std::cin >> b;
            v.push_back(b);
        }
        for (int i = a - 1; i > -1; i--) {
            if (s.find(v[i]) == s.end()) {
                r.push_back(v[i]);
                s.insert(v[i]);
            }
        }
        std::cout << r.size() << '\n';
        for (int i = r.size() - 1; i > 0; i--) {
            std::cout << r[i] << " ";
        }
        std::cout << r[0];
    } else {
        std::cout << 0;
    }
}