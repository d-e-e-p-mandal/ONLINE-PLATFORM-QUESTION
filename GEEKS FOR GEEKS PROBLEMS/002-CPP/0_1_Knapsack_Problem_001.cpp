// GFG : 0 - 1 Knapsack Problem : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximizedWeight(int W, vector<int> &val, vector<int> &wt, int ind, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(wt[0] <= W) return val[0];
            return 0;
        }
        // dp
        if(dp[ind][W] != -1) return dp[ind][W];
        
        // skip element
        int notPick = maximizedWeight(W, val, wt, ind-1, dp);
        
        // pick weight : each item is available in single quantity.
        int pick = INT_MIN;
        if(wt[ind] <= W) pick = val[ind] + maximizedWeight(W-wt[ind], val, wt, ind-1, dp);
        // maximum of notPick and pick
        return dp[ind][W] = max(notPick, pick);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1)); // datastructure
        return maximizedWeight(W, val, wt, n-1, dp);
    }
};

int main() {
    Solution sol;
    int W = 10;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {1, 2, 3};

    int result = sol.knapsack(W, val, wt);
    cout << "Maximum value in Knapsack = " << result << endl;
    return 0;
}
/*OUTPUT : Maximum value in Knapsack = 280*/
/*Time Complexity: O(n * W)
Space Complexity: O(n * W) + O(n) ← (DP table + recursion stack space) */