// GFG : Check if there exists a subsequence with sum K : Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));

        for(int i=0 ;i<=n; i++) dp[i][0] = true;
        
        for(int i = n-1; i>=0; i--){
            for(int j = 1; j <= k; j++ ){
                /* //not take
                dp[i][j] = dp[i + 1][j];  // not take
                //take
                if (j >= arr[i]) {
                     dp[i][j] = dp[i][j] || dp[i + 1][j - arr[i]];  // take
                }*/
                
                //same as previous comment code
                dp[i][j] = dp[i+1][j] || ((j >= arr[i]) ? dp[i+1][j - arr[i]] : false);
            }
        }

        return dp[0][k];
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

/*
class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: using only the first element
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        // Tabulation: fill dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;

                if (arr[i] <= j) {
                    take = dp[i - 1][j - arr[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][k];
    }
};
*/