/*
Q. Spiral order traversal on a matrix
*/

#include <vector>
#include <iostream>
using namespace std;
using matrix = vector<vector<int>>;

vector<int> spiral_order_traversal(matrix arr, int r, int c) {
    vector<int> spiral;
    int top = 0, left = 0, right = c - 1, bottom = r - 1;
    while (true) {
        if (top > bottom) break;
        for (int i = left; i <= right; i ++) { spiral.push_back(arr[top][i]); }
        top ++;

        if (left > right) break;
        for (int i = top; i <= bottom; i ++) { spiral.push_back(arr[i][right]); }
        right --;

        if (top > bottom) break;
        for (int i = right; i >= left; i --) { spiral.push_back(arr[bottom][i]); }
        bottom --;

        if (left > right) break;
        for (int i = bottom; i >= top; i --) { spiral.push_back(arr[i][left]); }
        left ++;
    }

    return spiral;
}

int main() {
    int r; cin >> r;
    int c; cin >> c;
    matrix arr;
    for (int i = 0; i < r; i ++) {
        vector<int> temp(c);
        for (int &i : temp) { cin >> i; }
        arr.push_back(temp);
    }

    auto spiral = spiral_order_traversal(arr, r, c);
    for (int i : spiral) { cout << i << " "; }
    cout << endl;

    return 0;
}
