// Leetcode : 416 : Partition Equal Subset Sum : Dynamic Programming : Memoisation (Top Down)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i]; //sum 
        if(sum & 1)return false; // if sum odd number it can not be devided into two equl part so return false
        int target = sum/2;
        //dp to store result of recursion call
        vector<bool>dp(target+1);
        //base case
        dp[0] = true;
        if(nums[0]<=target)dp[nums[0]] = true;// (row = 0) initilize

        //iteration
        for(int i=1; i<n; i++) { //starting from row 1
            vector<bool> curr(target+1);
            curr[0] = true; // if target is 0 then it is always true
            for(int j=0; j<=target; j++) {
                bool notPick = dp[j]; //not pick copy previous row
                bool pick = false;
                if (j >= nums[i])pick = dp[j - nums[i]];
                curr[j] = notPick || pick;
            }
            dp = curr;
        }
        
        return dp[target]; //result stored in last indexx
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
Space Complexity: O(n )*/