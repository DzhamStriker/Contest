#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool inmap(std::set<int> v, int a) {
    return v.find(a) != v.end();
}

double path(std::map<int, std::set<int>> coor, int x, int y, int number) {
    double sum = 0;
    for (auto i : coor) {
        for (int j : i.second) {
            sum += abs(x - i.first) + abs(y - j);
        }
    }
    return sum / number;
}

std::pair<int, int> square(int x, int y, std::map<int, std::set<int>> coor, int number) {
    double result = path(coor, x - 5, y - 5, number);
    int bestx = x - 5;
    int besty = y - 5;
    for (int i = x - 5; i < x + 6; i++) {
        for (int j = y - 5; j < y + 6; j++) {
            if (!inmap(coor[i], j)) {
                double preres = path(coor, i, j, number);
                if (preres < result) {
                    result = preres;
                    bestx = i;
                    besty = j;
                }
            }
        }
    }
    std::pair<int, int> p;
    p.first = bestx;
    p.second = besty;
    return p;
}

int main() {
    int number, a, b, x, y;
    std::cin >> number;
    std::map<int, int> hor, vert;
    std::map<int, std::set<int>> coor;
    for (int i = 0; i < number; i++) {
        std::cin >> a;
        hor[a]++;
        std::cin >> b;
        vert[b]++;
        coor[a].insert(b);
    }
    int sum = 0;
    for (auto i : hor) {
        sum += i.second;
        if (sum >= (number + 1) / 2) {
            x = i.first;
            break;
        }
    }
    sum = 0;
    for (auto i : vert) {
        sum += i.second;
        if (sum >= (number + 1) / 2) {
            y = i.first;
            break;
        }
    }
    if (!inmap(coor[x], y)) {
        std::cout << x << " " << y;
    } else {
        std::pair<int, int> res = square(x, y, coor, number);
        std::cout << res.first << " " << res.second;
    }
}