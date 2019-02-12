#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int M, N;
    string line;
    vector<vector<string>> data;
    cin >> M;
    int N_prev = 0;
    for (int j = 0; j < M; j++) {
        cin >> N;
        vector<string> list;
        data.push_back(list);
        if (N > N_prev) {
            N_prev = N;
        }
        for (int i = 0; i < N; i++) {
            cin >> line;
            data[j].push_back(line);
        }
    }
    for (int i = 0; i < N_prev; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (data[j].size() >= i + 1) {
                cout << data[j][i] << '\t';
            } else {
                cout << '\t';
            }
        }
        if (data[M - 1].size() >= i + 1) {
            cout << data[M - 1][i];
        }
        cout << '\n';
    }
}