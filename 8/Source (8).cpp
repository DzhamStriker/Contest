#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int sum = 0;
    int size = line.size();
    int i = 0;
    while (i < size) {
        char ch = line[i];
        if (!(ch & 0x80)) {
            ++i;
        } else if ((ch & 0xf0) == 0xf0) {
            i += 4;
        } else if ((ch & 0xe0) == 0xe0) {
            i += 3;
        } else if ((ch & 0xc0) == 0xc0) {
            i += 2;
        }
        sum++;
    }
    cout << sum << endl;
    return 0;
}