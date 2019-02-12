#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string call;
    vector<string> result;
    getline(cin, call);
    if (call.find("-c") == string::npos) {
        while (getline(cin, call)) {
            result.push_back(call);
        }
    } else {
        string sub = call.substr(3, call.size() - 3);
        int number = stoi(sub);
        while (getline(cin, call)) {
            int counter = 1;
            int begin = 0;
            bool isour = false;
            bool isfound = false;
            for (int i = 0; i < call.size(); i++) {
                if (call[i] == '\t') {
                    if (isour) {
                        result.push_back(call.substr(begin, i - begin));
                        i = call.size();
                        isour = false;
                        isfound = true;
                    } else {
                        counter++;
                        begin = i + 1;
                    }
                } else {
                    if (counter == number) {
                        isour = true;
                    }
                }
            }
            if (isour) {
                result.push_back(call.substr(begin, call.size() - begin));
                isfound = true;
            }
            if (!isfound) {
                result.push_back("");
            }
        }
    }
    for (string s : result) {
        cout << s << endl;
    }
}