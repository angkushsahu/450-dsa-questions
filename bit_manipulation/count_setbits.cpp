/*
Q. Count set bits in an integer
*/

#include <iostream>
#include <vector>
using namespace std;

int set_bits(int n) {
    int set_bits_count = 0;
    while (n) {
        set_bits_count += (n % 2 == 0) ? 0 : 1;
        n /= 2;
    }
    return set_bits_count;
}

int main() {
    int n; cin >> n;
    cout << set_bits(n) << endl;
    return 0;
}
