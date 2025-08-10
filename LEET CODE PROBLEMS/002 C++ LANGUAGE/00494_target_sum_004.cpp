// LeetCode : 494 : Target Sum : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totalsum = 0;

        for(int i=0; i<n; i++) totalsum+= nums[i];
        int range = abs(target) + totalsum;

        vector<vector<int>> dp(n, vector<int> (2*range+1, 0));

        //base case : ind 0 mark with 2 and other nums[0] mark both +ve and -ve
        if(nums[0] == 0) dp[0][0+range] = 2;
        else {                          
            dp[0][nums[0]+range] = 1;
            dp[0][-nums[0]+range] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<= 2*range; j++) {
                // include all number so check previous which index is used
                if(dp[i-1][j] != 0) {
                    int add = j+nums[i];
                    int sub = j-nums[i];
                    
                    // update form previous line : all possible update add and sub that cell how much type of possibility
                    dp[i][add] += dp[i-1][j];
                    dp[i][sub] += dp[i-1][j];
                }
            }
        }

        // return the desired cell : output
        return dp[n-1][range+target];
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << sol.findTargetSumWays(nums, target) << endl;

    return 0;
}