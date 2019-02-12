#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, bit;
    cin >> num >> bit;
    std::cout << (num ^ (1 << bit)) << std::endl;
}
