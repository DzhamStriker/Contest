#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, bit, num1;
    cin >> num >> bit;
    num1 = ~((~0) << bit);
    std::cout << (num & num1) << std::endl;
}