/*
Q. Count inversions
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long int;

ll merge(vector<ll> &arr, ll low, ll mid, ll high) {
    ll inversions = 0, i = low, j = mid + 1;
    vector<ll> temp;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) { temp.push_back(arr[i ++]); }
        else {
            temp.push_back(arr[j ++]);
            inversions += mid - i + 1;
        }
    }

    while (i <= mid) { temp.push_back(arr[i ++]); }
    while (j <= high) { temp.push_back(arr[j ++]); }

    for (int iter = low; iter <= high; iter ++) { arr[iter] = temp[iter - low]; }

    return inversions;
}

ll merge_sort(vector<ll> &arr, ll low, ll high) {
    ll inversions = 0;
    if (low < high) {
        ll mid = (low + high) / 2;
        inversions += merge_sort(arr, low, mid);
        inversions += merge_sort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }
    return inversions;
}


int main() {
    ll size; cin >> size;
    vector<ll> arr(size);
    for (ll &i : arr) { cin >> i; }

    cout << merge_sort(arr, 0, size - 1);

    return 0;
}
