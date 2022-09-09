/*
Q. Best time to buy and sell stock
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maximize_profit(vector<int> &arr, int size) {
    int min_so_far = INT_MAX;
    int max_so_far = INT_MIN;

    for (int i : arr) {
        min_so_far = min(min_so_far, i);
        max_so_far = max(max_so_far, i - min_so_far);
    }

    return max_so_far;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << maximize_profit(arr, size) << endl;

    return 0;
}
