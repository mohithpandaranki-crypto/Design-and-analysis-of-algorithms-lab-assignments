
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n + 1), val(n + 1);
    cout << "Enter weight and value of each item:\n";
    for (int i = 1; i <= n; i++) cin >> wt[i] >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];                      
            if (wt[i] <= w)                               
                dp[i][w] = max(dp[i][w], val[i] + dp[i - 1][w - wt[i]]);
        }
    }

    cout << "\nMaximum value: " << dp[n][W] << "\n";

    cout << "Items selected (1-indexed): ";
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {  
            cout << i << " ";
            w -= wt[i];
        }
    }
    cout << "\n";
    return 0;
}

