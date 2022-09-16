/*
Q. Find if there is any subarray with sum equal to 0
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// string find_subarray_equals_zero(vector<int> arr, int size) {
//     for (int i = 0; i < size; i ++) {
//         int sum = 0;
//         for (int j = i; j < size; j ++) {
//             sum += arr[j];
//             if (!sum) { return "YES"; }
//         }
//     }

//     return "NO";
// }

string find_subarray_equals_zero(vector<int> arr, int size) {
    set<int> s;
    int sum = 0;
    for (int i : arr) {
        s.insert(sum);
        sum += i;
        if (s.find(sum) != s.end()) { return "YES"; }
    }

    return "NO";
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << find_subarray_equals_zero(arr, size) << endl;

    return 0;
}
