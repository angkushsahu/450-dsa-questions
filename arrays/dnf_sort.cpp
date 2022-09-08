/*
Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void dnf_sort(vector<int> &arr, int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) { swap(arr[mid ++], arr[low ++]); }
        else if (arr[mid] == 1) { mid ++; }
        else { swap(arr[mid], arr[high --]); }
    }
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    dnf_sort(arr, size);

    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}