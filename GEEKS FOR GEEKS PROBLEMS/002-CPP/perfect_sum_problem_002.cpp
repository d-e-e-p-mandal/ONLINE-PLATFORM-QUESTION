// GFG : Perfect Sum Problem : Dynamic programming (Tabulation)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // column represent target : arr[i] can achive target 
        // base case target 0 always achive because not pick all : 1 
        for(int i=0; i<n; i++) dp[i][0] = 1;
        
        if(arr[0] <= target) dp[0][arr[0]] = 1; // 1st only q true set by direct
        if(arr[0] == 0) dp[0][0] = 2; //
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=target; j++){
                // copy old result not picking this
                int notPick = dp[i-1][j];
                // with pick
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i-1][j-arr[i]];
                // ans : notPick + pick
                dp[i][j] = notPick + pick;
            }
        }
        
        return dp[n-1][target];
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
Space Complexity: O(n * target))*/