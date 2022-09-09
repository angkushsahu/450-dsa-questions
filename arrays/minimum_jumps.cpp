/*
Q. Minimum number of jumps to reach end of an array
*/

#include <iostream>
#include <vector>
using namespace std;

int duplicate_detection(vector<int> arr, int size) {
    if (size == 1) { return 0; }
    int jumps = 0;
    int position = 0;
    int max_inside_jump_range = 0;

    for (int i = 0; i < size - 1; i ++) {
        max_inside_jump_range = max(max_inside_jump_range, arr[i] + i);
        if (position == i) {
            if (arr[position] == 0 && max_inside_jump_range == position) { return -1; }
            position = max_inside_jump_range;
            jumps ++;
        }
    }

    return jumps;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << duplicate_detection(arr, size) << endl;

    return 0;
}
