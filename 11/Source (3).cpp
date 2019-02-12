#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string line, M;
    getline(cin, M);
    N = stoi(M);
    vector<string> v;
    vector<int> result;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        v.push_back(line);
    }
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        if (line != v[i]) {
            result.push_back(i);
        }
    }
    for (int i : result) {
        cout << i << '\n';
    }
}