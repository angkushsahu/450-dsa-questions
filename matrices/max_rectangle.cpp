/*
Q. Max rectangle with all ones
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

vector<int> previous_smaller(vector<int> arr, int size) {
    vector<int> prev_small(size);
    stack<int> s;
    for (int i = 0; i < size; i ++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) { s.pop(); }
        if (s.empty()) { prev_small[i] = -1; }
        else { prev_small[i] = s.top(); }
        s.push(i);
    }

    return prev_small;
}

vector<int> next_smaller(vector<int> arr, int size) {
    vector<int> next_small(size);
    stack<int> s;
    for (int i = size - 1; i >= 0; i --) {
        while (!s.empty() && arr[s.top()] >= arr[i]) { s.pop(); }
        if (s.empty()) { next_small[i] = size; }
        else { next_small[i] = s.top(); }
        s.push(i);
    }

    return next_small;
}

int max_histogram(vector<int> arr, int size) {
    int max_ans = 0;
    vector<int> prev_small = previous_smaller(arr, size);
    vector<int> next_small = next_smaller(arr, size);

    for (int i = 0; i < size; i ++) {
        int current_ans = (next_small[i] - prev_small[i] - 1) * arr[i];
        max_ans = max(max_ans, current_ans);
    }

    return max_ans;
}

int largest_area(matrix arr, int r, int c) {
    vector<int> current_row = arr[0];
    int max_ans = max_histogram(current_row, c);

    for (int i = 1; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (arr[i][j]) { current_row[j] ++; }
            else { current_row[j] = 0; }
        }
        int current_ans = max_histogram(current_row, c);
        max_ans = max(max_ans, current_ans);
    }

    return max_ans;
}

int main() {
    int r; cin >> r;
    int c; cin >> c;
    matrix arr;
    for (int i = 0; i < r; i ++) {
        vector<int> temp(c);
        for (int &j : temp) { cin >> j; }
        arr.push_back(temp);
    }

    cout << largest_area(arr, r, c) << endl;

    return 0;
}
