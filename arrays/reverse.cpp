/*
Q. Reverse array in groups
*/

#include <vector>
#include <iostream>
using namespace std;

void reverse_array(vector<int> &arr, int size, int k) {
    for (int i = 0; i < size; i += k) {
        int low = i;
        int high = min(i + k - 1, size - 1);
        while (low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low ++; high --;
        }
    }
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    reverse_array(arr, size, k);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
