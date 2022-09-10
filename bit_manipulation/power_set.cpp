/*
Q. Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> find_all_subsequences(string str) {
    vector<string> ans;
    int length = str.length();
    int number_of_subsequences = (1 << length);

    for (int i = 0; i < number_of_subsequences; i ++) {
        string temp_string;
        for (int j = 0; j < length; j ++) {
            if (i & (1 << j)) { temp_string.push_back(str[j]); }
        }
        if (!temp_string.empty()) {
            ans.push_back(temp_string);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str; cin >> str;
    vector<string> ans = find_all_subsequences(str);
    for (string i : ans) { cout << i << " "; }
    cout << endl;

    return 0;
}
