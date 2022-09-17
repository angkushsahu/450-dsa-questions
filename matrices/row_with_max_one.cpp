/*
Q. Find the first row with maximum ones
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

int find_row_with_max_ones(matrix arr, int r, int c) {
    int j = c - 1, max_row_idx = -1;
    for (int i = 0; i < r; i ++) {
        bool flag = false;
        while (j >= 0 && arr[i][j]) {
            j --;
            flag = true;
        }
        if (flag) { max_row_idx = i; }
    }

    return max_row_idx;
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

    return 0;
}
