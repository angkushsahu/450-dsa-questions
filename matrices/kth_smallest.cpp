/*
Q. Find the kth smallest element in a matrix
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

int count_less_than_equal_to_mid(vector<int> arr, int size, int element) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (arr[mid] <= element) { low = mid + 1; }
        else { high = mid - 1; }
    }

    return low;
}

int kth_minimum(matrix arr, int r, int c, int k) {
    int low = arr[0][0], high = arr[r - 1][c - 1];
    while (low <= high) {
        int mid = (low + high) >> 1;
        int count = 0;
        for (vector<int> i : arr) { count += count_less_than_equal_to_mid(i, i.size(), mid); }
        if (count < k) { low = mid + 1; }
        else { high = mid - 1; }
    }

    return low;
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
    int k; cin >> k;

    cout << kth_minimum(arr, r, c, k) << endl;

    return 0;
}
