// GFG : Check if there exists a subsequence with sum K : Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isSum(vector<int> &arr, int k, int index, vector<vector<int>> &dp){
        if(k == 0) return true;
        if( k < 0) return false;
        if(index == arr.size()) return false;
        
        if(dp[index][k] != -1) return dp[index][k];
        
        if(isSum(arr, k, index+1, dp) == true) return dp[index][k] = true;
        if(isSum(arr, k-arr[index], index+1, dp) == true) return dp[index][k] = true;
        
        
        return dp[index][k] = false;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        
        return isSum(arr, k, 0, dp);
    }
};

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