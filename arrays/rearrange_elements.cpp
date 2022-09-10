/*
Q. Rearrange the array in alternating positive and negative items with O(1) extra space
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void rearrange_elements(vector<int> &arr, int size) {
	int i = -1;
	for (int j = 0; j < size; j ++) {
		if (arr[j] < 0) {
			i ++;
			if (i != j) { swap(arr[i], arr[j]); }
		}
	}
	// the above piece of code is exactly the same as the partitioning logic of quicksort algorithm, (the pivot in this case is 0 as we are interrogating for negative and positive elements)
	int positive_index = i + 1;
	int negative_index = 1; // value should be 0 if first position should be positive and 1 if first position is to be negative
	while (positive_index < size && arr[negative_index] < 0 && negative_index < positive_index) {
		swap(arr[negative_index], arr[positive_index]);
		negative_index += 2;
		positive_index ++;
	}

}

int main() {
	int size; cin >> size;
	vector<int> arr(size);
	for (int &i : arr) { cin >> i; }

	rearrange_elements(arr, size);
	for (int i : arr) { cout << i << " "; }
	cout << endl;

	return 0;
}
