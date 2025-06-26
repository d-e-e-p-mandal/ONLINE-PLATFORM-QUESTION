//LeetCode : 70 : Climbing Stairs : Dynamic Programming : (Tabulation (Bottom-Up))
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0] = dp[1] = 1; // initialize

        for(int i = 2; i <= n; i++) { // iterative approach
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    int n = 5; // Example input
    int result = sol.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << result << endl;

    return 0;
}

/*Output : Number of ways to climb 5 stairs: 8*/
/*Time Complexity : O(N) 
Space Complexity : O(N) */