// GFG : Rod Cutting : Dynamic Programming : Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPrice(vector<int>& price,int N, int ind, vector<vector<int>>& dp) {
        // base case : index 0 means length is 1 (length = index +1)
        if(ind == 0) return N * price[0];
        // or
        // another base case : this 
        // if(ind == -1) return 0; // No value when lenght is 0, means rod is not cutting

        // dp
        if(dp[ind][N] != -1) return dp[ind][N];
        
        int notTake = maximumPrice(price, N, ind-1, dp); // notPick
        // pick
        int take = INT_MIN; // or 0 : based on constraints
        if(ind + 1 <= N) take = price[ind] + maximumPrice(price, N-(ind+1), ind, dp); // length = index +1
        
        return dp[ind][N] = max(notTake, take);
    }
  public:
    int cutRod(vector<int> &price) {
        // length of rod is size of array
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1)); // dp
        
        return maximumPrice(price, n, n-1, dp);
    }
};

int main() {
    // Sample Input
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    Solution obj;
    cout << obj.cutRod(price) << endl; // Expected Output: 22
    return 0;
}

/* OUTPUT : 22 */
/*Time Complexity: O(n²), Space Complexity: O(n² + n) (DP table + recursion stack).*/
