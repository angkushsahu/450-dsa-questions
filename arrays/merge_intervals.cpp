/*
Q. Merge intervals
    example --> intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> merge_intervales(vector<vector<int>> &arr, int size) {
    vector<vector<int>> ans;
    int a = arr[0][0];
    int b = arr[0][1];

    if (size == 0 || size == 1) { return arr; }
    sort(arr.begin(), arr.end());
    vector<int> temp = arr[0];

    for (auto i : arr) {
        if (i[0] <= temp[1]) { temp[1] = max(i[1], temp[1]); }
        else {
            ans.push_back(temp);
            temp = i;
        }
    }

    ans.push_back(temp);
    return ans;
}

int main() {
    int size; cin >> size;
    vector<vector<int>> arr(size);
    for (auto &i : arr) {
        int a; cin >> a;
        int b; cin >> b;
        vector<int> temp = {a, b};
        cout << endl;
        i = temp;
    }

    auto ans = merge_intervales(arr, size);
    for (auto i : ans) {
        for (int j : i) { cout << j << " "; }
        cout << endl;
    }

    return 0;
}
