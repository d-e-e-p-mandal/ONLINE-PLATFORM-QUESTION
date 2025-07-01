// GFG : Check if there exists a subsequence with sum K : Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isSum(vector<int> &arr, int k, int index, vector<vector<int>> &dp){
        if(k == 0) return true;
        if(index == arr.size()-1) return (arr[arr.size() -1] == k);
        
        //if already checked
        if(dp[index][k] != -1) return dp[index][k];
        //if condition true then return don't go next
        //not pick
        if(isSum(arr, k, index+1, dp) == true) return dp[index][k] = true;
        //pick
        if(arr[index] <= k) if(isSum(arr, k-arr[index], index+1, dp) == true) return dp[index][k] = true;
        
        return dp[index][k] = false;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        
        return isSum(arr, k, 0, dp);
    }
};

// 🚀 MAIN FUNCTION TO RUN TEST CASES
int main() {
    Solution sol;

    vector<int> arr = {3, 1, 4, 2};
    int k = 6;

    bool result = sol.checkSubsequenceSum(arr.size(), arr, k);

    if (result) {
        cout << "Yes, there exists a subsequence with sum " << k << endl;
    } else {
        cout << "No, such subsequence does not exist." << endl;
    }

    return 0;
}

/*Output : Yes, there exists a subsequence with sum 6 */

/*#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function with memoization
    bool isSum(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: target sum achieved
        if (target == 0) return true;

        // Base case: only one element left
        if (index == 0) return arr[0] == target;

        // If already computed, return stored result
        if (dp[index][target] != -1) return dp[index][target];

        // Don't take current element
        bool notTake = isSum(index - 1, target, arr, dp);

        // Take current element (if it fits)
        bool take = false;
        if (arr[index] <= target) {
            take = isSum(index - 1, target - arr[index], arr, dp);
        }

        // Store and return the result
        return dp[index][target] = take || notTake;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return isSum(n - 1, k, arr, dp);
    }
};*/