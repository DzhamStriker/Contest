#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<deque>

using namespace std;

int main() {
    int N, M, number;
    vector<int> list1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> number;
        list1.push_back(number);
    }
    sort(list1.begin(), list1.end());
    cin >> M;
    for (int i = 0; i < M - 1; i++) {
        cin >> number;
        cout << upper_bound(list1.begin(), list1.end(), number) -
                lower_bound(list1.begin(), list1.end(), number) << " ";
    }
    cin >> number;
    cout << upper_bound(list1.begin(), list1.end(), number) -
            lower_bound(list1.begin(), list1.end(), number);
}