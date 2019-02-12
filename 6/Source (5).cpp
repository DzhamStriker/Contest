#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

bool sorting(string str1, string str2) {
    return str1 > str2;
}

int main() {
    string line;
    vector<string> result;
    getline(cin, line);
    if (line == "ASCENDING") {
        while (getline(cin, line)) {
            result.push_back(line);
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    } else if (line == "DESCENDING") {
        while (getline(cin, line)) {
            result.push_back(line);
        }
        sort(result.begin(), result.end(), sorting);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }
}