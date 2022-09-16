/*
Q. Find the triplet sum to a given value
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void find_triplet_sum(vector<int> arr, int size, int sum) {
    sort(arr.begin(), arr.end());
    // sort(arr, arr + size);

    for (int i = 0; i < size - 2; i ++) {
        int low = i + 1, high = size - 1;
        while (low < high) {
            int current_sum = arr[low] + arr[high] + arr[i];
            if (current_sum == sum) {
                cout << arr[low] << " " << arr[high] << " " << arr[i] << endl;
                return;
            }
            else if (current_sum < sum) { low ++; }
            else { high --; }
        }
    }

    cout << "No such triplet exists" << endl;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    int sum; cin >> sum;

    find_triplet_sum(arr, size, sum);

    return 0;
}
