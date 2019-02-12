#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include <iterator>

using namespace std;

int main() {
    set<char> line1, line2;
    set<char>::iterator it;
    string word;
    if (cin >> word) {
        for (int i = 0; i < word.size(); i++) {
            line1.insert(word[i]);
        }
        while (cin >> word) {
            set<char> line2;
            for (int i = 0; i < word.size(); i++) {
                line2.insert(word[i]);
            }
            set<char> result;
            set_intersection(line1.begin(), line1.end(), line2.begin(),
                             line2.end(), inserter(result, result.begin()));
            line1 = result;
        }
        for (char n : line1) {
            std::cout << n;
        }
    }
}