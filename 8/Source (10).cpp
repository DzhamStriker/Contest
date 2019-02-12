#include <vector>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> res = {};
    for (int i = 0; i < n; i++) {
        cin >> s;
        res.push_back(s);
    }
    for (auto i = 0; i < (1 << res.size()); ++i) {
        bitset<32> b(i);
        string pr;
        for (auto j = 0; j < res.size(); j++) {
            if (b[j]) {
                pr += res[j];
                pr += ",";
            }
        }
        if (!pr.empty()) {
            pr.pop_back();
        }
        cout << "[" << pr << "]" << endl;
    }
}