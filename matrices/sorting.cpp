/*
Q. Sort the given matrix
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using matrix = vector<vector<int>>;

matrix sort_matrix(matrix arr, int r, int c) {
    vector<int> temp;
    for (auto i : arr) {
        for (int j : i) { temp.push_back(j); }
    }

    int temp_iter = 0;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) { arr[i][j] = temp[temp_iter ++]; }
    }

    return arr;
}

int main() {
    int r; cin >> r;
    int c; cin >> c;
    matrix arr;
    for (int i = 0; i < r; i ++) {
        vector<int> temp(c);
        for (int &i : temp) { cin >> i; }
        arr.push_back(temp);
    }

    matrix ans = sort_matrix(arr, r, c);
    for (auto i : ans) {
        for (int j : i) { cout << j << " "; }
        cout << endl;
    }

    return 0;
}
