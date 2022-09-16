/*
Q. Array Subset of another array
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool is_subset(vector<int> arr_one, int size_one, vector<int> arr_two, int size_two) {
    int maximum = INT_MIN;
    for (int i : arr_one) { maximum = max(maximum, i); }
    vector<int> freq(maximum + 1, 0);

    for (int i : arr_one) { freq[i] ++; }
    for (int i : arr_two) {
        if (freq[i]) { freq[i] --; }
        else { return false; }
    }

    return true;
}

int main() {
    int size_one; cin >> size_one;
    vector<int> arr_one(size_one);
    for (int &i : arr_one) { cin >> i; }

    int size_two; cin >> size_two;
    vector<int> arr_two(size_two);
    for (int &i : arr_two) { cin >> i; }

    cout << is_subset(arr_one, size_one, arr_two, size_two) << endl;

    return 0;
}
