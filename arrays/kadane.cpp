/*
Q. Implement Kadane's algorithm
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int kadane(vector<int> arr, int size) {
    int sum = 0, max_sum = INT_MIN;

    for (int i : arr) {
        sum += i;
        max_sum = max(max_sum, sum);
        if (sum < 0) { sum = 0; }
    }

    return max_sum;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << kadane(arr, size) << endl;

    return 0;
}
