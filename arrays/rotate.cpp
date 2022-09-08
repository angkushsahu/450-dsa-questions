/*
Q. Write a program to cyclically rotate an array by one.
*/

#include <iostream>
#include <vector>
using namespace std;

void rotate_clockwise(vector<int> &arr, int size) {
    int last_element = arr[size - 1];

    for (int i = size - 2; i >= 0; i --) { arr[i + 1] = arr[i]; }
    arr[0] = last_element;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    rotate_clockwise(arr, size);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
