/*
Q. Find common elements in three sorted arrays
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> find_common_elements(vector<int> arr_one, vector<int> arr_two, vector<int> arr_three, int size_one, int size_two, int size_three) {
    vector<int> ans(1);
    int i = 0, j = 0, k = 0;
    while (i < size_one && j < size_two && k < size_three) {
        if ((arr_one[i] == arr_two[j]) && (arr_two[j] == arr_three[k])) {
            if (ans.size() && ans.back() != arr_one[i]) { ans.push_back(arr_one[i]); }
            i ++; j ++; k ++;
        }
        else if ((arr_one[i] <= arr_two[j]) && (arr_one[i] <= arr_three[k])) { i ++; }
        else if ((arr_two[j] <= arr_one[i]) && (arr_two[j] <= arr_three[k])) { j ++; }
        else if ((arr_three[k] <= arr_one[i]) && (arr_three[k] <= arr_two[j])) { k ++; }
    }

    ans.erase(ans.begin());
    return ans;
}

int main() {
    // first array
    int size_one; cin >> size_one;
    vector<int> arr_one(size_one);
    for (int &i : arr_one) { cin >> i; }

    // second array
    int size_two; cin >> size_two;
    vector<int> arr_two(size_two);
    for (int &i : arr_two) { cin >> i; }

    // third array
    int size_three; cin >> size_three;
    vector<int> arr_three(size_three);
    for (int &i : arr_three) { cin >> i; }

    vector<int> ans = find_common_elements(arr_one, arr_two, arr_three, size_one, size_two, size_three);
    for (int i : ans) { cout << i << " "; }
    cout << endl;

    return 0;
}
