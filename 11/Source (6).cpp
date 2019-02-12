#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string cat, line;
    vector<string> result;
    int counter = 1;
    bool E, n, s, T;
    getline(cin, cat);
    E = (cat.find("-E") != string::npos);
    n = (cat.find("-n") != string::npos);
    s = (cat.find("-s") != string::npos);
    T = (cat.find("-T") != string::npos);
    bool prev = false;
    while (getline(cin, line)) {
        if (line.size() != 0 || !prev) {
            string preres;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '\t' && T) {
                    preres += "^I";
                } else {
                    preres.push_back(line[i]);
                }
            }
            if (E) {
                preres = preres + "$";
            }
            if (n) {
                preres = to_string(counter) + " " + preres;
            }
            result.push_back(preres);
            counter++;
            if (line.size() == 0) {
                prev = true;
            } else {
                prev = false;
            }
        } else if (!s) {
            if (E) {
                line = line + "$";
            }
            if (n) {
                line = to_string(counter) + " " + line;
            }
            result.push_back(line);
            counter++;
            prev = true;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}