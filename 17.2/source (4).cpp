#include <iostream>

void move(int n, int x, int y) {
    if (n != 0) {
        if (x + y == 4) {
            move(n, x, 2);
            move(n, 2, y);
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