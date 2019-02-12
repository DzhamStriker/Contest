#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool CompareStr1(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    } else {
        for (int i = 0; i < str1.size(); i++) {
            int a = abs(static_cast<int>(str1[i]) - static_cast<int>(str2[i]));
            if (a != 0 && a != 32) {
                return false;
            }
        }
        return true;
    }
}

bool CompareStr2(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    } else {
        for (int i = 0; i < str1.size(); i++) {
            int a = abs(static_cast<int>(str1[i]) - static_cast<int>(str2[i]));
            if (a != 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    string wc, line;
    vector<pair<int, string>> result;
    bool c, d, i, u;
    getline(cin, wc);
    c = (wc.find("-c") != string::npos);
    d = (wc.find("-d") != string::npos);
    i = (wc.find("-i") != string::npos);
    u = (wc.find("-u") != string::npos);
    bool first = false;
    string previous;
    int counter = -1;
    while (getline(cin, line)) {
        if (first) {
            pair<int, string> par;
            par.first = 1;
            par.second = line;
            result.push_back(par);
            previous = line;
            counter++;
        } else {
            if (i) {
                if (CompareStr1(line, previous)) {
                    result[counter].first = result[counter].first + 1;
                } else {
                    pair<int, string> par;
                    par.first = 1;
                    par.second = line;
                    result.push_back(par);
                    previous = line;
                    counter++;
                }
            } else {
                if (CompareStr2(line, previous)) {
                    result[counter].first = result[counter].first + 1;
                } else {
                    pair<int, string> par;
                    par.first = 1;
                    par.second = line;
                    result.push_back(par);
                    previous = line;
                    counter++;
                }
            }
        }
    }
    if (d && !u) {
        if (c) {
            for (auto i : result) {
                if (i.first != 1) {
                    cout << i.first << " " << i.second << endl;
                }
            }
        } else {
            for (auto i : result) {
                if (i.first != 1) {
                    cout << i.second << endl;
                }
            }
        }
    } else if (!d && u) {
        if (c) {
            for (auto i : result) {
                if (i.first == 1) {
                    cout << i.first << " " << i.second << endl;
                }
            }
        } else {
            for (auto i : result) {
                if (i.first == 1) {
                    cout << i.second << endl;
                }
            }
        }
    } else if (!d && !u) {
        if (c) {
            for (auto i : result) {
                cout << i.first << " " << i.second << endl;
            }
        } else {
            for (auto i : result) {
                cout << i.second << endl;
            }
        }
    }
}