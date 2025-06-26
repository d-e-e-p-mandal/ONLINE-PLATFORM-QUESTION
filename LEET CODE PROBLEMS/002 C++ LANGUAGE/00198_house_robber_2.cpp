// Leetcode : 198 : House Robber : Dynamic Programming : (Tabulation (Bottom-Up))
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Tabulation (Bottom-Up)
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        dp[0] = nums[0]; // 1st step if

        for(int i = 1; i < n; i++) {
            if(i - 2 >= 0) nums[i] += dp[i - 2]; // boundary case check (i = 1)
            dp[i] = max((nums[i]), dp[i - 1]); // store maximum
        }

        return dp[n - 1]; // result stored in last index
    }
};

int main() {
    Solution sol;

    vector<int> houses = {2, 7, 9, 3, 1}; // Example input
    int result = sol.rob(houses);        // Call rob function

    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}

/*Output : Maximum amount that can be robbed: 12 */
/*Time Complexity : O(N)
Space Complexity : O(N)*/