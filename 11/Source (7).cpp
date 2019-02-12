#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int CountWords(string strString) {
    int nSpaces = 0;
    unsigned int i = 0;
    for (i; i < strString.length(); i++) {
        if (!isspace(strString.at(i))) {
            nSpaces++;
            while ((i < strString.length()) && !isspace(strString.at(i))) {
                i++;
            }
        } else {
            while ((i < strString.length()) && isspace(strString.at(i))) {
                i++;
            }
        }
    }
    return nSpaces;
}

int main() {
    string wc, line;
    int counter = 1;
    bool m, l, L, w;
    int mc = 0;
    int lc = 0;
    int Lc = 0;
    int wcc = 0;
    getline(cin, wc);
    m = (wc.find("-m") != string::npos);
    l = (wc.find("-l") != string::npos);
    L = (wc.find("-L") != string::npos);
    w = (wc.find("-w") != string::npos);
    while (getline(cin, line)) {
        if (m) {
            mc += line.length() + 1;
        }
        if (l) {
            lc++;
        }
        if (L) {
            if (Lc < line.length()) {
                Lc = line.length();
            }
        }
        if (w) {
            wcc += CountWords(line);
        }
    }
    string result;
    if (l) {
        result = result + to_string(lc) + " ";
    }
    if (w) {
        result = result + to_string(wcc) + " ";
    }
    if (m) {
        result = result + to_string(mc) + " ";
    }
    if (L) {
        result = result + to_string(Lc) + " ";
    }
    result.pop_back();
    cout << result;
}