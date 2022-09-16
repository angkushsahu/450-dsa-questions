/*
Q. Median of two sorted arrays of different sizes
*/

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

float find_median(vector<int> arr_one, vector<int> arr_two, int size_one, int size_two) {
    if (size_one > size_two) { return find_median(arr_two, arr_one, size_two, size_one); }
    int low = 0, high = size_one - 1;

    while (low <= high) {
        int cut_one = (low + high) >> 1;
        int cut_two = ((size_one + size_two + 1) >> 1) - cut_one;

        int left_one = !cut_one ? INT_MIN : arr_one[cut_one - 1];
        int left_two = !cut_two ? INT_MIN : arr_two[cut_two - 1];
        int right_one = cut_one == size_one ? INT_MAX : arr_one[cut_one];
        int right_two = cut_two == size_two ? INT_MAX : arr_two[cut_two];

        if (left_one <= right_two && left_two <= right_one) {
            if (!((size_one + size_two) & 1)) { return (max(left_one, left_two) + min(right_one, right_two)) / 2.0; }
            else { return max(left_one, left_two); }
        }
        else if (left_one > right_two) { high = cut_one - 1; }
        else { low = cut_one + 1; }
    }

    return 0.0;
}

int main() {
    int size_one; cin >> size_one;
    vector<int> arr_one(size_one);
    for (int &i : arr_one) { cin >> i; }

    int size_two; cin >> size_two;
    vector<int> arr_two(size_two);
    for (int &i : arr_two) { cin >> i; }

    cout << find_median(arr_one, arr_two, size_one, size_two) << endl;

    return 0;
}
