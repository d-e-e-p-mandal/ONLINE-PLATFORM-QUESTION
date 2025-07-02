// Leetcode : 416 : Partition Equal Subset Sum : Dynamic Programming : Memoisation (Top Down)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        // base case
        if(target == 0) return true;
        if(target < 0) return false;
        if(index == 0) return (nums[index] == target);

        // dp 
        if(dp[index][target] != -1) return dp[index][target];

        int x = (backtrack(nums, index-1, target - nums[index], dp)); //pick
        int y = (backtrack(nums, index-1, target, dp)); //not pick

        return dp[index][target] = x || y; //one of them true return true
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i]; //sum of all
        if(sum & 1) return false; // if sum odd number it cannot be divided equally

        //dp to store result of recursion call
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));

        return backtrack(nums, n - 1, sum / 2, dp);
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 5, 11, 5};

    bool result = sol.canPartition(nums);
    cout << "Can partition: " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*Output : Can partition: Yes */

/*Time Complexity: O(n * target)
Space Complexity: O(n * target)+ O(n)*/