/*
Q. Division without using multiplication, division and mod operator
*/

#include <climits>
#include <iostream>
using namespace std;
using ll = long long int;

ll divide(ll dividend, ll divisor) {
    if (!divisor) { return INT_MAX; }

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    ll quotient = 0, temp = 0;
    for (int i = 31; i >= 0; i --) {
        if (temp + (divisor << i) <= dividend) {
            temp += (divisor << i);
            quotient |= (1LL << i);
            // quotient += (1LL << i) also works here
        }
    }

    return (sign == -1) ? -quotient : quotient;
}

int main() {
    ll dividend, divisor;
    cin >> dividend >> divisor;

    cout << divide(dividend, divisor) << endl;

    return 0;
}
