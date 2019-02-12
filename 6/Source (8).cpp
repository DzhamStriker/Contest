#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

bool sorting(string str1, string str2) {
    return str1 > str2;
}

int main() {
    int N, page;
    string name;
    map<string, set<int>> result;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> page >> name;
        if (result.find(name) == result.end()) {
            set<int> empty = {};
            empty.insert(page);
            result[name] = empty;
        } else {
            result[name].insert(page);
        }
    }
    for (const auto &myPair : result) {
        cout << myPair.first;
        set<int> kek;
        kek = myPair.second;
        for (int n : kek) {
            cout << ' ' << n;
        }
        cout << '\n';
    }
}