//GFG : Knapsack with Duplicate Items : Dynamic Programming : Memoization
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int total(vector<int>& val, vector<int>& wt, int capacity, int ind, vector<vector<int>>& dp) {
        if(ind == -1) return 0; // base case : if it calculate all case go outside of index
        
        // dp
        if(dp[ind][capacity] != -1) return dp[ind][capacity];
        // notPick index
        int notPick = 0 + total(val, wt, capacity, ind-1, dp);
        // pick index
        int pick = 0;
        if(wt[ind] <= capacity) pick = val[ind] + total(val, wt, capacity-wt[ind], ind, dp); // function call with same index
        
        return dp[ind][capacity] = max(notPick, pick); // maximum choice of notPick and pick
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1)); // dp
        return total(val, wt, capacity, n-1, dp);
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;
    int result = obj.knapSack(val, wt, capacity);

    cout << "Maximum value in Knapsack = " << result << endl;
    return 0;
}

/*OUTPUT : Maximum value in Knapsack = 220 */

/*
	Time Complexity: O(n * capacity) → Each state (ind, capacity) is computed once.
	Space Complexity: O(n * capacity + n) → O(n * capacity) for DP array, plus O(n) recursion stack space.
*/