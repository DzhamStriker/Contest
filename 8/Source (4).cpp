#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, bit;
    cin >> num >> bit;
    std::cout << (1 == ((num >> bit) & 1)) << std::endl;
}
