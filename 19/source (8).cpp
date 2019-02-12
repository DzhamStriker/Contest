#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>

class Heap {
 private:
    std::vector<int> numbers;

 public:
    size_t getsize() {
        return numbers.size();
    }

    void insert(int key) {
        numbers.push_back(key);
        int i = this->getsize() - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && numbers[parent] < numbers[i]) {
            int num = numbers[i];
            numbers[i] = numbers[parent];
            numbers[parent] = num;
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void fix(int i) {
        int left;
        int right;
        int largest;
        for (; ; ) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            largest = i;
            if (left < this->getsize() && numbers[left] > numbers[largest]) {
                largest = left;
            }
            if (right < this->getsize() && numbers[right] > numbers[largest]) {
                largest = right;
            }
            if (largest == i) {
                break;
            }
            int num = numbers[i];
            numbers[i] = numbers[largest];
            numbers[largest] = num;
            i = largest;
        }
    }

    explicit Heap(std::vector<int> list) {
        numbers = list;
        for (int i = this->getsize() / 2; i > -1; i--) {
            this->fix(i);
        }
    }

    int getMax() {
        int result = numbers[0];
        numbers[0] = numbers[this->getsize() - 1];
        numbers.pop_back();
        this->fix(0);
        return result;
    }
};

std::vector<int> heapSort(std::vector<int> list) {
    Heap heap(list);
    for (int i = list.size() - 1; i >= 0; i--) {
        int max = heap.getMax();
        list[i] = max;
    }
    return list;
}

int main() {
    int c, a, b;
    std::cin >> c;
    std::vector<int> num;
    for (int i = 0; i < c; i++) {
        std::cin >> a;
        num.push_back(a);
    }
    num = heapSort(num);
    int i = 0;
    for (; i < c - 1; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << num[i];
}