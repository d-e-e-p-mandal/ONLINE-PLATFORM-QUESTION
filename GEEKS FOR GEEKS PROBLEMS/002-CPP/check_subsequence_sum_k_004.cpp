// GFG : Check if there exists a subsequence with sum K : Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Create a dp table of size (n+1) x (k+1)
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        // Base Case: Sum 0 is always possible with empty subsequence
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Build the dp table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                // Not take current element
                dp[i][j] = dp[i + 1][j];

                // Take current element if safe
                if (arr[i] >= 0 && j >= arr[i]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j - arr[i]];
                }
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
        // Previous row (i-1)
        vector<bool> prev(k + 1, false);
        prev[0] = true;  // Base case: sum 0 is always possible

        // Handle first element
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }

        // Loop through elements from index 1 to n-1
        for (int i = 1; i < n; i++) {
            vector<bool> curr(k + 1, false);
            curr[0] = true;  // sum 0 is always possible

            for (int j = 1; j <= k; j++) {
                bool notTake = prev[j];
                bool take = false;

                if (arr[i] <= j) {
                    take = prev[j - arr[i]];
                }

                curr[j] = take || notTake;
            }

            prev = curr;  // Move current row to previous for next iteration
        }

        return prev[k];
    }
};
*/