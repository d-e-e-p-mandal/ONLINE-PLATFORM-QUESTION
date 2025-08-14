//GFG : Knapsack with Duplicate Items : Dynamic Programming : Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0)); // dp
        
        // base case : index 0 : all element 0 : we take all element of dp is 0 so we don't need write base case, it already satisfy base case
        
        for(int i=1; i<=n; i++) {  // index start at 1 : index 0 in base case (index -1 is represented as 0 : using +1 with all index)
            for(int j=0; j<=capacity; j++) { // capacity
                int notPick = dp[i-1][j]; //not pick index
                
                int pick = 0;
                if(wt[i-1] <= j) pick = val[i-1] + dp[i][j-wt[i-1]]; // pick index : wt and val index 0 to n-1
                
                dp[i][j] = max(notPick, pick); // maximum of both
            }
        }
        
        
        return dp[n][capacity];
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