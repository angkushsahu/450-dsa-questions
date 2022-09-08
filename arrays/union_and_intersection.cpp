/*
Q. Find the union and intersection of two sorted arrays
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void union_of_arrays(vector<int> arr_one, int size_one, vector<int> arr_two, int size_two) {
    set<int> s;
     int i = 0, j = 0;

    while (i < size_one && j < size_two) {
        if (arr_one[i] < arr_two[j]) {
            s.insert(arr_one[i]);
            i ++;
        }
        else if (arr_one[i] > arr_two[j]) {
            s.insert(arr_two[j]);
            j ++;
        }
        else {
            s.insert(arr_two[j]);
            j ++; i ++;
        }
    }

    while (i < size_one) { s.insert(arr_one[i ++]); }
    while (j < size_two) { s.insert(arr_two[j ++]); }

    for (int i : s) { cout << i << " "; }
    cout << endl;
}

void intersection_of_arrays(vector<int> arr_one, int size_one, vector<int> arr_two, int size_two) {
    set<int> s;
    int i = 0, j = 0;

    while (i < size_one && j < size_two) {
        if (arr_one[i] == arr_two[j]) {
            s.insert(arr_one[i]);
            i ++; j ++;
        }
        else if (arr_one[i] < arr_two[j]) { i ++; }
        else { j ++; }
    }

    for (int i : s) { cout << i << " "; }
    cout << endl;
}

int main() {
    int size_one; cin >> size_one;
    vector<int> arr_one(size_one);
    for (int &i : arr_one) { cin >> i; }

    int size_two; cin >> size_two;
    vector<int> arr_two(size_two);
    for (int &i : arr_two) { cin >> i; }

    union_of_arrays(arr_one, size_one, arr_two, size_two);
    intersection_of_arrays(arr_one, size_one, arr_two, size_two);

    return 0;
}
