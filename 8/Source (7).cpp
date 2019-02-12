#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int num, max, num1, d, num2;
    int len;
    cin >> num;
    num1 = num;
    len = 0;
    d = 1;
    while (num1) {
        len++;
        num1 &= ~d;
        d = d << 1;
    }
    max = num;
    num2 = ~((~0) << len);
    for (int i = 0; i < len - 1; i++) {
        num = ((num >> 1) | (num << (len - 1))) & num2;
        if (num > max) {
            max = num;
        }
    }
    cout << max;
}