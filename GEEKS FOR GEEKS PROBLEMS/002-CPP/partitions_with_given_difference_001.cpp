// GFG : Partitions with Given Difference : Dynamic Programming (Memoization) : 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int noOfSubset(vector<int>& arr, int target, int ind, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(target == 0 && arr[0] == 0) return 2; // if arr[0] = 0 then no of subset return 2 because we calculate base case manually
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        // use of dp
        if(dp[ind][target] != -1) return dp[ind][target];
        // not pick skip index
        int notPick = noOfSubset(arr, target, ind-1, dp);
        
        // pick index
        int pick = 0;
        if(arr[ind] <= target) pick = noOfSubset(arr, target-arr[ind], ind-1, dp);
        
        return dp[ind][target] = pick + notPick; // stored result total ans with pick and notPick
    }

  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        
        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += arr[i];
        // s1 - s2 = d; s1 + s2 = s
        // s - 2s2 = d;
        // s2 = (s-d)/2;
        int target = (totalSum - d);
        if(target < 0 || target % 2 != 0) return 0; // odd number cannot divide two equal parts
        
        target /= 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return noOfSubset(arr, target, n-1, dp);
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 1, 2, 3};  // Example input
    int d = 1;                       // Example difference

    int result = sol.countPartitions(arr, d);
    cout << "Number of valid subset partitions: " << result << endl;

    return 0;
}

/*OUTPUT : Number of valid subset partitions: 3*/
/*Time Complexity: O(n * target)
Space Complexity: O(n * target) + O(n) ← (DP table + recursion stack space) */