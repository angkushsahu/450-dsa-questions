/*
Q. Find the two non-repeating elements in an array of repeating elements
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> find_non_repeating_elements(vector<int> arr, int size) {
    int xor_sum = 0;
    for (int i : arr) { xor_sum ^= i; }

    int temp_xorsum = xor_sum, position = 0, rightmost_setbit = 0;
    while (!rightmost_setbit) {
        rightmost_setbit = temp_xorsum & 1;
        position ++;
        temp_xorsum = temp_xorsum >> 1;
    }
    position --;
    int new_xorsum = 0;
    for (int i : arr) {
        if (i & (1 << position)) { new_xorsum ^= i; }
    }

    int unique_element_one = new_xorsum ^ xor_sum;
    int unique_element_two = new_xorsum;

    vector<int> ans;
    if (unique_element_one < unique_element_two) {
        ans.push_back(unique_element_one);
        ans.push_back(unique_element_two);
    } else {
        ans.push_back(unique_element_two);
        ans.push_back(unique_element_one);
    }

    return ans;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    vector<int> single_numbers = find_non_repeating_elements(arr, size);
    for (int i : single_numbers) { cout << i << " "; }
    cout << endl;

    return 0;
}
