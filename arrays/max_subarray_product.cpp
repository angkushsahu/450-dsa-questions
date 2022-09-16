/*
Q. Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long int;

void swap(ll &a, ll &b) {
    int temp = a;
    a = b;
    b = temp;
}

ll maximum_subarray_product(vector<int> arr, int size) {
    ll maximum = INT_MIN, minimum = INT_MAX, ans = INT_MIN;
    for (int i : arr) {
        if (i <= 0) { swap(maximum, minimum); }
        maximum = max(i * 1LL, i * maximum);
        minimum = min(i * 1LL, i * minimum);
        ans = max(ans, max(minimum, maximum));
    }

    return ans;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << maximum_subarray_product(arr, size) << endl;

    return 0;
}
