#include <vector>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, m, bit;
    int counter = 0;
    cin >> n >> m;
    string s;
    vector<bitset<22>> res = {};
    for (int i = 0; i < n; i++) {
        bitset<22> a;
        for (int j = 0; j < m; j++) {
            cin >> bit;
            a.set(m - j - 1, bit);
        }
        res.push_back(a);
    }
    for (auto i = 0; i < (1 << res.size()); ++i) {
        bitset<32> b(i);
        bitset<22> k;
        k = ~k;
        k = k << m;
        for (auto j = 0; j < res.size(); j++) {
            if (b[j]) {
                k |= res[j];
            }
        }
        k = ~k;
        if (k == 0) {
            counter++;
        }
    }
    cout << counter;
}