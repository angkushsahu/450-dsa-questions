/*
Q. Find the kth maximum and minimum element in an array (k will be provided by the user)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    sort(arr.begin(), arr.end());

    cout << arr[k - 1] << endl;

    return 0;
}
