#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<deque>

using namespace std;

bool pairCompare(const pair<string, int>& pair1, const pair<string, int>& pair2) {
    if (pair1.second == pair2.second) {
        return pair1.first < pair2.first;
    }
    return pair1.second > pair2.second;
}

string make_key(deque<string>& key) {
    string result;
    for (int i = 0; i < key.size() - 1; i++) {
        result.append(key[i]);
        result.append(" ");
    }
    result.append(key.back());
    return result;
}

int main() {
    int N, M;
    deque<string> key;
    map<string, int> result;
    vector<pair<string, int>> result1;
    string word;
    cin >> M >> N;
    if (N <= M) {
        for (int i = 0; i < N; i++) {
            cin >> word;
            key.push_back(word);
        }
        string preres = make_key(key);
        result[preres] = 1;
        for (int i = N; i < M; i++) {
            cin >> word;
            key.push_back(word);
            key.pop_front();
            string preres = make_key(key);
            if (result.find(preres) == result.end()) {
                result[preres] = 1;
            } else {
                result[preres] += 1;
            }
        }
        for (const auto &myPair : result) {
            pair<string, int> str;
            str.first = myPair.first;
            str.second = myPair.second;
            result1.push_back(str);
        }
        sort(result1.begin(), result1.end(), pairCompare);
        for (int i = 0; i < result1.size(); i++) {
            cout << result1[i].first << " - " << result1[i].second << '\n';
        }
    } else {
        for (int i = 0; i < M; i++) {
            cin >> word;
        }
    }
}