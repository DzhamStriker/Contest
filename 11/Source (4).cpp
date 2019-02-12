#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    string str, rep, sub, line;
    getline(cin, sub);
    getline(cin, rep);
    vector<string> result;
    vector<char> v1(sub.begin(), sub.end());
    set<char> st(sub.begin(), sub.end());
    vector<char> v2(rep.begin(), rep.end());
    while (getline(cin, line)) {
        vector<char> v(line.begin(), line.end());
        for (int i = 0; i < v.size(); i++) {
            if (st.find(v[i]) != st.end()) {
                size_t p = find(v1.begin(), v1.end(), v[i]) - v1.begin();
                line.replace(i, 1, string(1, v2[p]));
            }
        }
        result.push_back(line);
    }
    for (string s : result) {
        cout << s << '\n';
    }
}