/*
Q. Find all pairs on integer array whose sum is equal to given number
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_pairs(vector<int> &arr, int size, int k) {
    unordered_map<int, int> m;

    for (int i : arr) { m[i] ++; }
    int twice_count = 0;

    for (int i : arr) {
        twice_count += m[k - i];
        if (k - i == i) { twice_count --; }
    }
    return twice_count / 2;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    cout << count_pairs(arr, size, k) << endl;

    return 0;
}
