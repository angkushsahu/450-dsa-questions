/*
Q. Find duplicate in an array of N+1 Integers
*/

#include <iostream>
#include <vector>
using namespace std;

int duplicate_detection(vector<int> arr, int size) {
    for (int i : arr) {
        if (arr[abs(i)] < 0) { return i < 0 ? -i : i; }
        arr[abs(i)] = -arr[abs(i)];
    }

    return -1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size + 1);
    for (int &i : arr) { cin >> i; }

    cout << duplicate_detection(arr, size) << endl;

    return 0;
}
