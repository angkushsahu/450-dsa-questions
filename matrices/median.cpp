/*
Q. Find the median in a row-wise sorted median where the number of rows and columns are always odd
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

int count_smaller_or_equal_to_mid(vector<int> arr, int size, int element) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (arr[mid] <= element) { low = mid + 1; }
        else { high = mid - 1; }
    }

    return low;
}

int find_median(matrix arr, int r, int c) {
    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int count = 0;
        for (auto i : arr) { count += count_smaller_or_equal_to_mid(i, c, mid); }
        int mid_of_matrix = (r * c) >> 1;
        if (count <= mid_of_matrix) { low = mid + 1; }
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

    cout << find_median(arr, r, c) << endl;

    return 0;
}
