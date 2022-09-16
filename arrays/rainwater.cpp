/*
Q. Trapping rainwater problem
*/

#include <vector>
#include <iostream>
using namespace std;
using ll = long long int;

ll trapped_rainwater(vector<int> arr, int size) {
    int left = 0, right = size - 1;
    ll sum = 0;
    int max_left = 0, max_right = 0;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= max_left) { max_left = arr[left]; }
            else { sum += max_left - arr[left]; }
            left ++;
        } else {
            if (arr[right] >= max_right) { max_right = arr[right]; }
            else { sum += max_right - arr[right]; }
            right --;
        }
    }

    return sum;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << trapped_rainwater(arr, size) << endl;

    return 0;
}
