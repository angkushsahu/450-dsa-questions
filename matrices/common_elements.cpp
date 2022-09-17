/*
Q. Find a common element in all rows of a given row-wise sorted matrix
*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
using matrix = vector<vector<int>>;

int find_common_elements(matrix arr, int r, int c) {
    unordered_map<int, int> count;
    for (int i = 0; i < r; i ++) {
        count[arr[i][0]] ++;
        for (int j = 1; j < c; j ++) {
            if (arr[i][j] != arr[i][j - 1]) { count[arr[i][j]] ++; }
        }
    }

    for (auto i : count) {
        if (i.second == r) { return i.first; }
    }
    return -1;
}

int main() {
    int r; cin >> r;
    int c; cin >> c;
    matrix arr;
    for (int i = 0; i < r; i ++) {
        vector<int> temp(c);
        for (int &j : temp) { cin >> j; }
        arr.push_back(temp);
    }

    cout << find_common_elements(arr, r, c) << endl;

    return 0;
}
