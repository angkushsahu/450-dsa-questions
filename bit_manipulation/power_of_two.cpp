/*
Q. Program to find whether a no is power of two
*/

#include <iostream>
using namespace std;

using ll = long long int;

bool is_power_of_two(ll n) {
    if (!n) { return false; }

    while (n != 1) {
        if (n & 1) { return false; }
        n = n >> 1;
    }

    return true;
}

int main() {
    ll n; cin >> n;
    cout << is_power_of_two(n) << endl;

    return 0;
}
