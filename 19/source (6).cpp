#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>

int main() {
    std::map<char, std::vector<std::string>> list;
    int m;
    int k = 0;
    std::string s;
    std::cin >> m;
    if (m != 0) {
        std::vector<std::string> arr;
        std::vector<std::string> arr2;
        for (int j = 0; j < m; j++) {
            std::cin >> s;
            arr.push_back(s);
        }
        std::string symb = "0123456789";
        std::cout << "Initial array:\n";
        int i = 0;
        for (i = 0; i < m - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[i] << "\n";
        std::cout << "**********\n";
        int siz = arr[0].size();
        for (int i = 0; i < siz; i++) {
            for (int j = 0; j < m; j++) {
                list[arr[j][siz - i - 1]].push_back(arr[j]);
            }
            std::cout << "Phase " << i + 1 << '\n';
            for (int j = 0; j < 10; j++) {
                if (list.find(symb[j]) == list.end()) {
                    std::cout << "Bucket " << j << ": empty\n";
                } else {
                    std::cout << "Bucket " << j << ": ";
                    for (k = 0; k < list[symb[j]].size() - 1; k++) {
                        std::cout << list[symb[j]][k] << ", ";
                        arr2.push_back(list[symb[j]][k]);
                    }
                    std::cout << list[symb[j]][k] << '\n';
                    arr2.push_back(list[symb[j]][k]);
                }
            }
            std::cout << "**********\n";
            arr = arr2;
            arr2.clear();
            list.clear();
        }
        std::cout << "Sorted array:\n";
        for (i = 0; i < m - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[i] << "\n";
    }
}