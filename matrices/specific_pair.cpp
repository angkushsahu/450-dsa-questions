/*
Q. Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
*/

#include <vector>
#include <climits>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

int find_maximum_value(matrix arr, int r, int c) {
    int max_value = INT_MIN, current_max_value = arr[r - 1][c - 1];
    // matrix temp_matrix;
    // for (int i = 0; i < r; i ++) {
    //     vector<int> temp_arr(c);
    //     for (int &j : temp_arr) { j = 0; }
    //     temp_matrix.push_back(temp_arr);
    // }
    int temp_matrix[r][c] = { 0 };
    temp_matrix[r - 1][c - 1] = arr[r - 1][c - 1];

    for (int i = c - 2; i >= 0; i --) {
        current_max_value = max(current_max_value, arr[r - 1][i]);
        temp_matrix[r - 1][i] = current_max_value;
    }
    current_max_value = arr[r - 1][c - 1];
    for (int i = r - 2; i >= 0; i --) {
        current_max_value = max(current_max_value, arr[i][c - 1]);
        temp_matrix[i][c - 1] = current_max_value;
    }

    for (int i = r - 2; i >= 0; i --) {
        for (int j = c - 2; j >= 0; j --) {
            max_value = max(max_value, temp_matrix[i + 1][c + 1] - arr[i][j]);
            temp_matrix[i][j] = max(arr[i][j], max(temp_matrix[i + 1][j], temp_matrix[i][j + 1]));
        }
    }

    return max_value;
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

    cout << find_maximum_value(arr, r, c) << endl;

    return 0;
}
