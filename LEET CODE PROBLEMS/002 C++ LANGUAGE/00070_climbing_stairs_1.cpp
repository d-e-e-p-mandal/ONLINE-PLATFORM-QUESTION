//LeetCode : 70 : Climbing Stairs : Dynamic Programming :  Memoization (top-down DP)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalSteps(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n]; // already calculate
        
        return dp[n] = totalSteps(n-1, dp) + totalSteps(n-2, dp); // calculate steps and store
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1); // dp to store result

        return totalSteps(n,dp);
    }
};

int main() {
    Solution sol;
    
    int n = 5; // Example input
    int result = sol.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << result << endl;

    return 0;
}

/*Output : Number of ways to climb 5 stairs: 8 */

/*Time Complexity : O(N) 
Space Complexity : O(N) */