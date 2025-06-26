// Leetcode : 198 : House Robber : Dynamic Programming : (Memoization (Top-Down))
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Memoization (Top-Down)
    int totalAmount(vector<int> &nums, int index, vector<int> &dp){
        if(index == 0) return nums[0];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index]; // stored in dp

        int pick = nums[index] + totalAmount(nums, index - 2, dp); // pick index and previous index -2
        int notPick = 0 + totalAmount(nums, index - 1, dp); // previous index

        return dp[index] = max(pick, notPick); // store maximum
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // dp

        return totalAmount(nums, n - 1, dp);
    }
};

int main() {
    Solution sol;

    vector<int> houses = {2, 7, 9, 3, 1}; // Example input
    int maxAmount = sol.rob(houses);     // Call rob function

    cout << "Maximum amount that can be robbed: " << maxAmount << endl;

    return 0;
}

/* OUTPUT : Maximum amount that can be robbed: 12 */
/*Time Complexity : O(n)
Space Complexity : O(n)*/