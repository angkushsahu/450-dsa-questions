/*
Q.Rotate a matrix by 90 degree in clockwise direction without using any extra space
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

void rotate_matrix(matrix &arr, int n) {
    for (int i = 0; i < n / 2; i ++) {
        for (int j = i; j < n - i - 1; j ++) {
            int temp = arr[i][j];
            arr[i][j] = arr[n - j - 1][i];
            arr[n - j - 1][i] = arr[n - 1 - i][n - 1 - j];
            arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i];
            arr[j][n - 1 - i] = temp;
        }
    }
}

int main() {
    int n; cin >> n;
    matrix arr;
    for (int i = 0; i < n; i ++) {
        vector<int> temp(n);
        for (int &j : temp) { cin >> j; }
        arr.push_back(temp);
    }

    rotate_matrix(arr, n);
    for (auto i : arr) {
        for (int j : i) { cout << j << " "; }
        cout << endl;
    }

    return 0;
}
