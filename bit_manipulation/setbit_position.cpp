/*
Q. Find position of the only set bit
*/

#include <iostream>
using namespace std;

int set_bits(int x, int y, int l, int r) {
    if (l < 1 || r > 32) { return x; }
    int mask_length = (1LL << (r - l + 1)) - 1;
    int mask = (mask_length << (l - 1)) & y;
    return (x | mask);
}

int main() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;

    cout << set_bits(x, y, l, r) << endl;

    return 0;
}
