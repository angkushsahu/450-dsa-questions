/*
Q. Smallest subarray with sum greater than a given number
*/

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int sub_array(vector<int> arr, int size, int x) {
    int minimum = INT_MAX, i = 0, j = 0, sum = 0;
    while (i <= j && j < size) {
        while (sum <= x && j < size) { sum += arr[j ++]; }
        while (sum > x && i < j) {
            minimum = min(minimum, j - i);
            sum -= arr[i ++];
        }
    }

    return minimum;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int x; cin >> x;

    cout << sub_array(arr, size, x) << endl;

    return 0;
}
