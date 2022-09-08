/*
Q. Move all the negative elements to one side of the array
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void negatives_aside(vector<int> &arr, int size) {
    int low = 0, high = size - 1;
    while (low < high) {
        if (arr[low] > 0) { swap(arr[low], arr[high --]); }
        low ++;
    }
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    negatives_aside(arr, size);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
