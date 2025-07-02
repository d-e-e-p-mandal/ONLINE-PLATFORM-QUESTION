// Leetcode : 416 : Partition Equal Subset Sum : Dynamic Programming : Tabulation (Buttom Up)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i]; //sum of all
        if(sum & 1)return false; // if sum odd number it can not be devided into two equl part so return false
        int target = sum/2;
        //dp to store result of recursion call
        vector<vector<bool>> dp(n, vector<bool>(target+1));
        //base case
        for(int i=0; i<n; i++)dp[i][0] = true; //target reach 0 it always true
        if(nums[0]<=target)dp[0][nums[0]] = true;// (row = 0) initilize

        //iteration
        for(int i=1; i<n; i++) { //starting from row 1
            for(int j=0; j<=target; j++) {
                bool notPick = dp[i - 1][j]; //not pick copy previous row
                bool pick = false;
                if (j >= nums[i])pick = dp[i - 1][j - nums[i]];
                dp[i][j] = notPick || pick;
            }
        }
        
        return dp[n-1][target]; //result stored in last indexx
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
Space Complexity: O(n * target)*/