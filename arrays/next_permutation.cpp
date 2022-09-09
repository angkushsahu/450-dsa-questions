/*
Q. Find next permutation of a given array
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find_next_permutation(vector<int> &arr, int size) {
    int iter = size - 2;
    while (iter >= 0 && arr[iter] >= arr[iter + 1]) { iter --; }
    if (iter >= 0) {
        int _iter = size - 1;
        while (arr[_iter] <= arr[iter]) { _iter --; }
        swap(arr[iter], arr[_iter]);
    }

    // reversing the array from index = value of iterator
    int limit = ((iter + 1) + size) / 2;
    reverse(arr.begin() + iter + 1, arr.end());
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    find_next_permutation(arr, size);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
