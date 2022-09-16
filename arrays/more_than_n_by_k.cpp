/*
Q. Given an array of size n and a number k, find all elements that appear more than n/k times
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int more_than_n_by_k(vector<int> arr, int size, int k) {
    unordered_map<int, int> m;
    int x = size / k;

    for (int i : arr) { m[i] ++; }

    int count = 0;
    for (auto i : m) {
        if (i.second > x) {
            cout << i.first << " ";
            count ++;
        }
    }
    cout << endl;

    return count;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    cout << more_than_n_by_k(arr, size, k) << endl;

    return 0;
}
