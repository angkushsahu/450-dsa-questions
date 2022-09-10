/*
Q. Move all the negative elements to one side of the array
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void negatives_aside(vector<int> &arr, int size) {
    // the piece of code below is exactly the same as the partitioning logic of quicksort algorithm, (the pivot in this case is 0 as we are interrogating for negative and positive elements)
    int i = -1;
	for (int j = 0; j < size; j ++) {
		if (arr[j] < 0) {
			i ++;
			if (i != j) { swap(arr[i], arr[j]); }
		}
	}
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    negatives_aside(arr, size);
    for (int i : arr) { cout << i << " "; }
    cout << endl;

    return 0;
}
