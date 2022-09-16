/*
Q. Median of an array
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_median(vector<int> arr, int size) {
    sort(arr.begin(), arr.end());

    int middle_index = size / 2;
    if (size & 1) { return arr[middle_index]; }
    else {
        int average = (arr[middle_index - 1] + arr[middle_index]) / 2;
        return average;
    }
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << find_median(arr, size) << endl;

    return 0;
}
