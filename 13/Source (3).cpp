#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int min_index(vector<string> strs, vector<bool> empty) {
    int index = -1;
    for (int i = 0; i < strs.size(); i++) {
        if ((!empty[i])) {
            if (index == -1 || strs[i] < strs[index])
                index = i;
        }
    }
    return index;
}

int main() {
    int memory_size;
    int counter = 0;
    int number_of_file = 0;
    int r = 0;
    string str;
    ifstream infile;
    infile.open("memory.txt");
    getline(infile, str);
    memory_size = stoi(str);
    infile.close();
    infile.open("input.txt");
    vector<string> strings;
    while (getline(infile, str)) {
        strings.push_back(str);
        counter++;
        r++;
        if (counter == memory_size) {
            sort(strings.begin(), strings.end());
            ofstream o(to_string(number_of_file) + ".txt");
            number_of_file++;
            for (string s : strings) {
                o << s << '\n';
            }
            o.close();
            strings.clear();
            counter = 0;
        }
    }
    if (strings.size() != 0) {
        sort(strings.begin(), strings.end());
        ofstream o(to_string(number_of_file) + ".txt");
        number_of_file++;
        for (string s : strings) {
            o << s << '\n';
        }
        o.close();
        strings.clear();
        counter = 0;
    }
    vector<ifstream> files(number_of_file);
    vector<bool> is_empty(number_of_file);
    for (int i = 0; i < number_of_file; i++) {
        files[i].open(to_string(i) + ".txt");
        is_empty[i] = false;
        getline(files[i], str);
        strings.push_back(str);
    }
    int w = 0;
    ofstream myfile;
    myfile.open("output.txt");
    while (w < r) {
        int index = min_index(strings, is_empty);
        myfile << strings[index] << '\n';
        w++;
        if (getline(files[index], str)) {
            strings[index] = str;
        } else {
            files[index].close();
            remove((to_string(index) + ".txt").c_str());
            is_empty[index] = true;
        }
    }
    for (int i = 0; i < is_empty.size(); i++) {
        if (!is_empty[i]) {
            remove((to_string(i) + ".txt").c_str());
        }
    }
    myfile.close();
}