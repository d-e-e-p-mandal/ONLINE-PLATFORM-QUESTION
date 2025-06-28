// Leetcode : 213 : House Robber2 : Dynamic Programming : (Tabulation (Bottom-Up))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<int> &nums, int start, int end) {
        vector<int>dp(end);
        dp[start] = nums[start]; //stored the 1st index

        for(int i=start + 1; i<end; i++) {
            int pick = nums[i] + ((i-2 >= start)? dp[i-2] : 0);
            /*  alternative of previous line
            int pick = nums[i];
            if(i-2>=start) pick += dp[i-2]; */
            int notPick = 0 + dp[i-1];

            dp[i] = max(pick,notPick);
        }

        return dp[end - 1];
    }
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        // circular: divide into two parts (1st and last, pick only one at a time, and max of them)
        return max(maximumAmount(nums, 0 , n-1), maximumAmount(nums, 1 , n));
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