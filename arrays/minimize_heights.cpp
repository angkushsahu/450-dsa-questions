/*
Q. Minimise the maximum difference between heights [V.IMP]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_min_difference(vector<int> arr, int size, int k) {
    if (size == 1) { return 0; }
    sort(arr.begin(), arr.end());

    int min_height = arr[0];
    int max_height = arr[size - 1];
    int diff = max_height - min_height;

    for (int i = 1; i < size; i ++) {
        if (arr[i] - k < 0) { continue; }
        min_height = min(arr[0] + k, arr[i] - k);
        max_height = max(arr[i - 1] + k, arr[size - 1] - k);
        diff = min(diff, max_height - min_height);
    }

    return diff;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    cout << get_min_difference(arr, size, k) << endl;

    return 0;
}
