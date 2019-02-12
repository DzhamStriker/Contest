#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int main() {
    int a;
    char c;
    std::cin >> a;
    bool isfirst = false;
    char last;
    std::map<char, int> chars;
    for (int i = 0; i < a; i++) {
        std::cin >> c;
        chars[c]++;
    }
    std::string result;
    for (auto i : chars) {
        for (int j = 0; j < i.second / 2; j++) {
            result.push_back(i.first);
        }
        if (!isfirst) {
            if (i.second % 2 == 1) {
                isfirst = true;
                last = i.first;
            }
        }
    }
    std::string rev = result;
    std::reverse(rev.begin(), rev.end());
    if (isfirst) {
        std::cout << result << last << rev;
    } else {
        std::cout << result << rev;
    }
}