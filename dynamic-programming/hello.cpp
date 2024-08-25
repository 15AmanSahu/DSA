#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n = 4;
    int capacity = 7;

    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {20, 30, 40, 50};

    int maxValue = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
