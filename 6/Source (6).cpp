#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> result1, result2;
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        result1.push_back(line);
    }
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        cin >> line;
        result2.push_back(line);
    }
    if (equal(result1.begin(), result1.end(), result2.begin())) {
        cout << "EQUAL";
    } else {
        cout << "NOT EQUAL";
    }
}