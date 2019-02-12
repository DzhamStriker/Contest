#include<algorithm>
#include <numeric>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include <iterator>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int last_space, word, z, i;
        last_space = 0;
        word = 0;
        vector<string> words;
        string str, str1;
        set<char> all;
        set<char> zad;
        set<string> all1;
        set<string> zad1;
        for (i = 0; i < line.size(); i++) {
            if (static_cast<char> (line[i]) == ' ') {
                if (word == 0) {
                    cout << line.substr(last_space, i - last_space);
                    last_space = i + 1;
                    word = 1;
                } else if (word == 1) {
                    z = stoi(line.substr(last_space, i - last_space));
                    word = 2;
                    last_space = i + 1;
                } else if (word == 2) {
                    str = line.substr(last_space, i - last_space);
                    if (i - last_space == 1 &
                       (static_cast<int>(static_cast<char> (line[last_space])) >= 65
                       && static_cast<int>(static_cast<char> (line[last_space])) <= 90)) {
                        for (int j = 0; j < z; j++) {
                            all.insert(static_cast<char> (65 + j));
                        }
                        zad.insert(static_cast<char> (line[last_space]));
                        word = 3;
                    } else {
                        for (int j = 0; j < z; j++) {
                            all1.insert(to_string(j + 1));
                        }
                        zad1.insert(str);
                        word = 4;
                    }
                    last_space = i + 1;
                } else if (word == 3) {
                    zad.insert(static_cast<char> (line[last_space]));
                    last_space = i + 1;
                } else {
                    str = line.substr(last_space, i - last_space);
                    zad1.insert(str);
                    last_space = i + 1;
                }
            }
        }
        if (word == 1) {
            z = stoi(line.substr(last_space, i - last_space));
            for (int j = 0; j < z; j++) {
                cout << " " << j + 1;
            }
            cout << '\n';
        } else if (word == 2) {
            str = line.substr(last_space, i - last_space);
            if (i - last_space == 1 &
                (static_cast<int>(static_cast<char> (line[last_space])) >= 65
                    && static_cast<int>(static_cast<char> (line[last_space])) <= 90)) {
                for (int j = 0; j < z; j++) {
                    all.insert(static_cast<char> (65 + j));
                }
                zad.insert(static_cast<char> (line[last_space]));
                set<char> diff;
                set_difference(all.begin(), all.end(), zad.begin(), zad.end(),
                inserter(diff, diff.begin()));
                for (char n : diff) {
                    cout << " " << n;
                }
                cout << '\n';
            } else {
                set<int> all1;
                set<int> zad1;
                for (int j = 0; j < z; j++) {
                    all1.insert(j + 1);
                }
                zad1.insert(stoi(str));
                set<int> diff;
                set_difference(all1.begin(), all1.end(), zad1.begin(), zad1.end(),
                inserter(diff, diff.begin()));
                for (int n : diff) {
                    cout << " " << n;
                }
                cout << '\n';
            }
        } else if (word == 3) {
            zad.insert(static_cast<char> (line[i - 1]));
            set<char> diff;
            set_difference(all.begin(), all.end(), zad.begin(), zad.end(),
            inserter(diff, diff.begin()));
            for (char n : diff) {
                cout << " " << n;
            }
            cout << '\n';
        } else if (word == 4) {
            str = line.substr(last_space, i - last_space);
            zad1.insert(str);
            set<string> diff;
            set<int> diff1;
            set_difference(all1.begin(), all1.end(), zad1.begin(), zad1.end(),
            inserter(diff, diff.begin()));
            for (string n : diff) {
                diff1.insert(stoi(n));
            }
            for (int n : diff1) {
                cout << " " << n;
            }
            cout << '\n';
        }
    }
}