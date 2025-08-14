//GFG : Knapsack with Duplicate Items : Dynamic Programming : Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0)); // dp
        
        for(int j=0; j<= capacity; j++) { // calculate : index 0 
            dp[0][j] = j / wt[0] * val[0]; // base case take maxim val can take
        }
        
        for(int i=1; i<n; i++) {  // index start at 1 : index 0 is base case 
            for(int j=0; j<=capacity; j++) { // capacity
                int notPick = dp[i-1][j]; //not pick index
                
                int pick = 0;
                if(wt[i] <= j) pick = val[i] + dp[i][j-wt[i]]; // pick index : wt and val
                
                dp[i][j] = max(notPick, pick); // maximum of both
            }
        }
        
        
        return dp[n-1][capacity];
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
	Space Complexity: O(n * capacity) → O(n * capacity) for DP array.
*/