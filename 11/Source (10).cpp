#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string call;
    string opt;
    string word;
    string s;
    vector<string> result;
    getline(cin, call);
    opt = call.substr(0, 2);
    word = call.substr(3, call.size() - 3);
    if (opt == "-f") {
        while (getline(cin, s)) {
            if (s.find(word) != string::npos) {
                result.push_back(s);
            }
        }
    } else {
        while (getline(cin, s)) {
            if (s.find(word) == string::npos) {
                result.push_back(s);
            }
        }
    }
    for (string s : result) {
        cout << s << endl;
    }
}