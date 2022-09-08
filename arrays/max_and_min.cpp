/*
Q. Find the maximum and minimum element of an array
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    int max_element = INT_MIN;
    int min_element = INT_MAX;
    for (int i : arr) {
        max_element = max(max_element, i);
        min_element = min(min_element, i);
    }

    cout << max_element << " " << min_element << endl;

    return 0;
}
