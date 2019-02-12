#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string call;
    bool rev;
    bool tac;
    vector<string> result;
    getline(cin, call);
    rev = (call.find("--rev") != string::npos);
    tac = (call.find("--tac") != string::npos);
    while (getline(cin, call)) {
        if (rev) {
            reverse(call.begin(), call.end());
            result.push_back(call);
        } else {
            result.push_back(call);
        }
    }
    if (tac) {
        for (int i = result.size() - 1; i > -1; i--) {
            cout << result[i] << endl;
        }
    } else {
        for (string s : result) {
            cout << s << endl;
        }
    }
}