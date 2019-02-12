#include<algorithm>
#include <numeric>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<deque>

using namespace std;

int main() {
    float n;
    vector<float> numbers;
    while (cin >> n) {
        numbers.push_back(n);
    }
    cout << accumulate(numbers.begin(), numbers.end(), 0.);
}