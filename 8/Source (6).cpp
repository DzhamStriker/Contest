#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int num;
    int counter = 0;
    cin >> num;
    while (num) {
        counter++;
        num &= num - 1;
    }
    cout << counter;
}