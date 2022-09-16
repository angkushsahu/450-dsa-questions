/*
Q. Maximum profit by buying and selling a share at most twice
Way of thinking: (this is how I learnt this algorithm, your way of understanding it may vary)
step 1 : we take the negative version of the current element for ease of calculation and store it in first_buy
step 2 : we then add first_buy and first_sell (the reason we add these values is because first_buy is already negative therefore, it will end up getting subtracted)
step 3 : we then subtract the price of the current stock from the profit made by selling the first stock which is stored in first_buy currently and store it in second_buy
step 4 : we finally add the value of second_buy to second_sell to store the profit made by selling the second stock and the first stock
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int max_profit(vector<int> arr, int size) {
    int first_buy = INT_MIN, second_buy = INT_MIN;
    int first_sell  = 0, second_sell  = 0;

    for (int i : arr) {
        first_buy = max(first_buy, -i);
        first_sell = max(first_sell, i + first_buy);
        second_buy = max(second_buy, first_sell - i);
        second_sell = max(second_sell, second_buy + i);
    }

    return second_sell;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }

    cout << max_profit(arr, size) << endl;

    return 0;
}
