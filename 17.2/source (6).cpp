#include <iostream>

void move(int n, int x, int y) {
    if (n == 1) {
        if (x == 1) {
            std::cout << n << " " << 1 << " " << 3 << '\n';
        } else if (x == 3) {
            std::cout << n << " " << 3 << " " << 1 << '\n';
        }
    } else {
        move(n - 1, x, y);
        std::cout << n << " " << x << " " << 2 << '\n';
        move(n - 1, y, x);
        std::cout << n << " " << 2 << " " << y << '\n';
        move(n - 1, x, y);
    }
}

int main() {
    int n;
    std::cin >> n;
    move(n, 1, 3);
}