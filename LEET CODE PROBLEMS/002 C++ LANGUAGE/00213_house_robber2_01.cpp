// Leetcode : 213 : House Robber2 : Dynamic Programming : (Memoization (Top-Down))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    int maximumAmount(vector<int>& nums, int startingPoint, int index, vector<int> &dp){
        if(index < startingPoint) return 0;
        if(dp[index] != -1) return dp[index]; // if already calculated

        int pick = nums[index] + maximumAmount(nums, startingPoint, index - 2, dp);
        int notPick = 0 + maximumAmount(nums, startingPoint, index - 1, dp);

        return dp[index] = max(pick, notPick); // maximum of adjacent
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        // circular: divide into two parts (1st and last, pick only one at a time, and max of them)
        return max(maximumAmount(nums, 0, n - 2, dp1), maximumAmount(nums, 1, n - 1, dp2));
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the money in each house: ";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}


/*Output : 
Enter number of houses: 4
Enter the money in each house: 2 3 2 3 
Maximum amount that can be robbed: 5
*/

/*Time Complexity : O(N)
Space Complexity : O(N)*/