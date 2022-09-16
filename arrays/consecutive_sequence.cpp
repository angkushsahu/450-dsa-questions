/*
Q. Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
using namespace std;

int longest_subsequence(vector<int> arr, int size) {
    unordered_set<int> s;
    for (int i : arr) { s.insert(i); }

    int ans = 0;
    for (int i : arr) {
        if (s.find(i - 1) == s.end()) {
            int current_number = i;
            int current_longest_sequence = 1;
            while (s.find(current_number + 1) != s.end()) {
                current_number ++;
                current_longest_sequence ++;
            }
            ans = max(ans, current_longest_sequence);
        }
    }

    return ans;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << longest_subsequence(arr, size) << endl;

    return 0;
}
