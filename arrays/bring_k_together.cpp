/*
Q. Minimum number of swaps to bring together all the numbers which are less than or equal to a given number
*/

#include <vector>
#include <iostream>
using namespace std;

int minimum_swaps(vector<int> arr, int size, int k) {
    int count = 0;
    for (int i : arr) {
        if (i <= k) { count ++; }
    }

    int greater_element = 0;
    for (int i = 0; i < count; i ++) {
        if (arr[i] > k) { greater_element ++; }
    }

    int ans = greater_element;
    for (int i = 0, j = count; j < size; j ++, i ++) {
        if (arr[i] > k) { greater_element --; }
        if (arr[j] > k) { greater_element ++; }
        ans = min(ans, greater_element);
    }

    return ans;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int k; cin >> k;

    cout << minimum_swaps(arr, size, k) << endl;

    return 0;
}
