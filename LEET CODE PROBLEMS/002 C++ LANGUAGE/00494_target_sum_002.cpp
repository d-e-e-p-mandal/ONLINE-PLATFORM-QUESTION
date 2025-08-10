// LeetCode : 494 : Target Sum : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int total(vector<int>& nums, int target, int ind, vector<vector<int>>& dp, int range) {
        if(ind == 0){ // base case : if arr[0] = 0, so +ve and -ve are same return 2 : another run ind = -1 return -1
            if(target == 0 && nums[0] == 0) return 2;
            if(abs(target) == nums[0]) return 1; // for +ve and -ve nums[ind] both true
            return 0;
        }
        // dp
        if(dp[ind][target+range] != -1) return dp[ind][target+range];
        // add and sub
        int add = total(nums, target - nums[ind] , ind - 1, dp, range);
        int sub = total(nums, target + nums[ind], ind - 1, dp, range);

        return dp[ind][target+range] = add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totalsum = 0;
        // sum of all element
        for(int i=0; i<n; i++) totalsum+= nums[i];
        int range = abs(target) + totalsum; 

        vector<vector<int>> dp(n, vector<int> (2*range+1, -1)); // maximum range : -targe-sum to target+sum
        // using range index as target 0 index : 0 index -> range for handle negative case : actually shift all negative case start form 0  
        return total(nums, target, n-1, dp, range);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << sol.findTargetSumWays(nums, target) << endl;

    return 0;
}