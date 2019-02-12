#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int main() {
    int n, k, button;
    std::vector<int> buttons;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> button;
        buttons.push_back(button);
    }
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> button;
        buttons[button - 1] -= 1;
    }
    for (int i = 0; i < n; i++) {
        if (buttons[i] < 0) {
            std::cout << "yes" << '\n';
        } else {
            std::cout << "no" << '\n';
        }
    }
}