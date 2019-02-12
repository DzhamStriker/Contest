#include <iostream>

void move(int n, int x, int y) {
    if (n != 0) {
        move(n - 1, x, 6 - x- y);
        std::cout << n << " " << x << " " << y << '\n';
        move(n - 1, 6 - x - y, y);
    }
}

int main() {
    int n;
    std::cin >> n;
    move(n, 1, 3);
}