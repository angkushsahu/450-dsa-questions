/*
Q. Copy set bits in a range
*/

#include <iostream>
using namespace std;

int copy_setbits(int x, int y, int l, int r) {
    if (l < 1 || r > 32) { return -1; }
    int mask_length = (1LL << (r - l + 1)) - 1;
    int mask = (mask_length << (l - 1)) & y;
    return x | mask;
}

int main() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;

    cout << copy_setbits(x, y, l, r) << endl;

    return 0;
}