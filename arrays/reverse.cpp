/*
Q. Write a program to reverse an array
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse_array(vector<int> &arr, int size) {
    for (int i = 0; i < (size / 2); i ++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    reverse_array(arr, size);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
