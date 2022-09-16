/*
Q. Three way partitioning
*/

#include <vector>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitioning(vector<int> arr, int size, int a, int b) {
    int low = 0, high = size - 1;
    for (int i = 0; i <= high; i ++) {
        if (arr[i] < a) {
            if (i != low) { swap(arr[i], arr[low]); }
            low ++;
        }
        else if (arr[i] > b) {
            swap(arr[i], arr[high]);
            high --; i --;
        }
    }

    return 1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int a, b;
    cin >> a >> b;

    cout << partitioning(arr, size, a, b) << endl;

    return 0;
}
