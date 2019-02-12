#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

void delete_zeroes(std::vector<int>& numbers) {
    numbers.erase(remove(numbers.begin(), numbers.end(), 0), numbers.end());
}