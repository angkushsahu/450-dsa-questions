/*
Q. Search an element in a matrix
  The matrix has following properties :
  - Integers in each row are sorted from left to right.
  - The first integer of each row is greater than the last integer of the previous row.
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

bool is_element_present_in_matrix(matrix arr, int r, int c, int element) {
    int i = 0, j = c - 1;
    if (element < arr[0][0] || element > arr[r - 1][c - 1]) { return false; }
    while (i < r && j >= 0) {
        if (arr[i][j] == element) { return true; }
        else if (arr[i][j] < element) { i ++; }
        else { j --; }
    }

    return false;
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
    int element; cin >> element;

    cout << is_element_present_in_matrix(arr, r, c, element) << endl;

    return 0;
}
