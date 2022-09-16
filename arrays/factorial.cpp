/*
Q. Find the factorial of a large number
*/

#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<int> &arr, int size, int multiplier) {
    int carry = 0;
    for (int i = 0; i < size; i ++) {
        int product = arr[i] * multiplier + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        arr.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n) {
    vector<int> fact;
    fact.push_back(1);

    for (int i = 2; i <= n; i ++) {
        multiply(fact, fact.size(), i);
    }

    for (int i = fact.size() - 1; i >= 0; i --) { cout << fact[i]; }
}

int main() {
    int n; cin >> n;
    factorial(n);

    return 0;
}