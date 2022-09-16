/*
Q. Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
*/

#include <vector>
#include <iostream>
using namespace std;

bool is_palindrome(int n) {
    int temp_n = n, reverse_n = 0;
    while (n) {
        int last_digit = n % 10;
        n /= 10;
        reverse_n = reverse_n * 10 + last_digit;
    }

    return temp_n == reverse_n;
}

int is_palindromic_array(vector<int> arr, int size) {
    for (int i : arr) {
        if (!is_palindrome(i)) { return 0; }
    }

    return 1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << is_palindromic_array(arr, size) << endl;

    return 0;
}