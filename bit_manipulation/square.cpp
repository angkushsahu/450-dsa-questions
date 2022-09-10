/*
Q. Calculate square of a number without using *, / and pow()
*/

#include <iostream>
using namespace std;

int find_square(int n) {
    if (!n) { return n; }
    if (n < 0) { n = -n; }
    // dividing n by 2 and storing in half_of_n
    int half_of_n = n / 2;

    // if n is odd, use the formula (2x + 1)^2 --> 4x^2 + 4x + 1    (since, n = 2x + 1; n^2 = (2x + 1)^2)
    // if n is even, use the formula (2x)^2 --> 4x^2    (since, n = 2x; n^2 = (2x)^2)
    if (n & 1) { return (4 * find_square(half_of_n)) + (4 * half_of_n) + 1; }
    else { return 4 * find_square(half_of_n); }
}

int main() {
    int n; cin >> n;
    cout << find_square(n) << endl;

    return 0;
}
