/*
Q. Chocolate distribution problem
*/

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;

ll distribute_chocolate(vector<ll> arr, ll size, ll total_students) {
    if (size < total_students) { return -1; }
    sort(arr.begin(), arr.end());

    ll min_difference = INT_MAX;
    for (ll i = 0; i < size - total_students + 1; i ++) {
        ll difference = arr[i + total_students - 1] - arr[i];
        min_difference = min(min_difference, difference);
    }

    return min_difference;
}

int main() {
    ll size; cin >> size;
    vector<ll> arr(size);
    for (ll &i : arr) { cin >> i; }
    ll total_students; cin >> total_students;

    cout << distribute_chocolate(arr, size, total_students) << endl;

    return 0;
}
