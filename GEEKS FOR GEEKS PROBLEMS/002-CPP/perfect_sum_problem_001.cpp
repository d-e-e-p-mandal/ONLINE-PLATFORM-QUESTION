// GFG : Perfect Sum Problem : Dynamic programming (Memoization)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int noOfSubset(vector<int>& arr, int target, int ind, vector<vector<int>>& dp){
        if (ind == 0) {
            // if arr[0] = 0 then we need to return 2 because with and without it meets target and it is not participating pick and notPick(it's directly return from base case) example [0,0,1] output:4
            // we can also do if arr[0] return total subset * 2 : In this question * 2 use in perfectSum funtion 
            if (target == 0 && arr[0] == 0) return 2; 
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        // another : write base case ind == -1 : change dp according to base case


        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notPick = noOfSubset(arr, target, ind-1, dp); // skip element
        // pick element if arr[ind] > pick then don't need pick means pick is 0
        int pick = 0;
        if(arr[ind] <= target) pick = noOfSubset(arr, target-arr[ind], ind-1, dp);
        
        return dp[ind][target] = notPick + pick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1, -1));
        
        return noOfSubset(arr, target, n-1, dp);
    }
};

int main() {
    vector<int> arr = {0, 0, 1};
    int target = 1;

    Solution sol;
    int result = sol.perfectSum(arr, target);

    cout << "Number of subsets with sum " << target << " = " << result << endl;

    return 0;
} 

/* Output : Number of subsets with sum 1 = 4 */
/*Time Complexity: O(n * target)
Space Complexity: O(n * target) + O(n) (DP table + recursion stack)*/