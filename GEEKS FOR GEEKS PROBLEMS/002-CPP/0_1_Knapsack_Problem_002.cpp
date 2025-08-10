// GFG : 0 - 1 Knapsack Problem : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        // Base case initialization : 1st row initllize of max(val[0], 0) each cel because we take max pick and notPick 
        for (int j = 0; j <= W; j++) {
            if (wt[0] <= j) dp[0][j] = val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=W; j++){
                int notPick = dp[i-1][j];//copy previous
                // taking index
                int pick = INT_MIN;
                if(wt[i] <= j) pick = val[i] + dp[i-1][j - wt[i]]; 
                //store maximum
                dp[i][j] = max(notPick, pick);
             }
        }
        
        return dp[n-1][W];
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
Space Complexity: O(n * W) + O(n) */