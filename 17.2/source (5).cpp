#include <iostream>

void move(int n, int x, int y) {
    if (n != 0) {
        if (x == 1 && y == 3) {
            move(n - 1, 1, 3);
            std::cout << n << " " << 1 << " " << 2 << '\n';
            move(n - 1, 3, 1);
            std::cout << n << " " << 2 << " " << 3 << '\n';
            move(n - 1, 1, 3);
        } else if (x == 2 && y == 1) {
            move(n - 1, 2, 1);
            std::cout << n << " " << 2 << " " << 3 << '\n';
            move(n - 1, 1, 2);
            std::cout << n << " " << 3 << " " << 1 << '\n';
            move(n - 1, 2, 1);
        } else if (x == 3 && y == 2) {
            move(n - 1, 3, 2);
            std::cout << n << " " << 3 << " " << 1 << '\n';
            move(n - 1, 2, 3);
            std::cout << n << " " << 1 << " " << 2 << '\n';
            move(n - 1, 3, 2);
        } else {
            move(n - 1, x, 6 - x - y);
            std::cout << n << " " << x << " " << y << '\n';
            move(n - 1, 6 - x - y, y);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    move(n, 1, 3);
}