#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::string;

int main() {
    std::set<int> numbers;
    std::map<char, int> result;
    std::vector<char> chars;
    string line, text;
    int max = 0;
    while (cin >> line) {
        text.append(line);
    }
    for (int i = 0; i < text.size(); i++) {
        if (result.find(static_cast<char> (text[i])) == result.end()) {
            result[static_cast<char> (text[i])] = 1;
        } else {
            result[static_cast<char> (text[i])] += 1;
        }
    }
    for (const auto &myPair : result) {
        if (myPair.second > max) {
            max = myPair.second;
        }
    }
    for (int i = 0; i < max; i++) {
        for (const auto &myPair : result) {
            if (myPair.second + i < max) {
                cout << ' ';
            } else {
                cout << '#';
            }
        }
        cout << '\n';
    }
    for (const auto &myPair : result) {
        cout << myPair.first;
    }
}