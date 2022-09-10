/*
Q. Count number of bits to be flipped to convert A to B
*/

#include <iostream>
using namespace std;

int count_bits_to_be_flipped(int a, int b) {
    int count = 0;
    int n = a ^ b;
    while (n) {
        count ++;
        n &= (n - 1);
    }

    return count;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << count_bits_to_be_flipped(a, b) << endl;

    return 0;
}
