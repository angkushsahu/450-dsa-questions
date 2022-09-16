/*
Q. Count total set bits till n
*/

#include <iostream>
using namespace std;

int max_power_of_two(int n) {
    int c = 0;
    while ((1 << c) <= n) { c ++; }
    return c - 1;
}

int total_setbits_till_n(int n) {
    if (!n) { return n; }
    int x = max_power_of_two(n);
    int ans = (x * (1 << (x - 1))) + (n - (1 << x)) + 1 + total_setbits_till_n(n - (1 << x));
    return ans;
}

int main() {
    int n; cin >> n;
    cout << total_setbits_till_n(n) << endl;

    return 0;
}
