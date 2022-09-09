/*
Q. Merge two sorted arrays without using extra space
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge_arrays(vector<int> &arr_one, vector<int> &arr_two, int size_one, int size_two) {
    int i = 0, j = 0;
    while (i < size_one) {
        if (arr_one[i] > arr_two[j]) {
            swap(arr_one[i], arr_two[j]);
            int temp = arr_two[j];
            while (temp > arr_two[j + 1] && j < size_two - 1) {
                arr_two[j] = arr_two[j + 1];
                j ++;
            }
            arr_two[j] = temp;
            j = 0;
        }
        i ++;
    }
}

int main() {
    int size_one; cin >> size_one;
    vector<int> arr_one(size_one);
    for (int &i : arr_one) { cin >> i; }

    int size_two; cin >> size_two;
    vector<int> arr_two(size_two);
    for (int &i : arr_two) { cin >> i; }

    merge_arrays(arr_one, arr_two, size_one, size_two);

    // printing the sorted arrays
    for (int i : arr_one) { cout << i << " "; }
    cout << endl;
    for (int i : arr_two) { cout << i << " "; }
    cout << endl;

    return 0;
}
