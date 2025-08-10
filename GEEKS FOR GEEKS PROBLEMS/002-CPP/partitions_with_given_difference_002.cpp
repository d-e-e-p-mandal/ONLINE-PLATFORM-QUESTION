// GFG : Partitions with Given Difference : Dynamic Programming (Tabulation) : 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];
        // s1 - s2 = d; s1+s2 = s
        // s - 2s2 = d;
        // s2 = (s-d)/2;
        int target = (totalSum - d);
        if(target < 0 || target %2 != 0) return 0;//odd number can not devide two equl part
        
        target /=2;
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        // base case
        for(int i=0; i<n; i++) dp[i][0] = 1;
        // ind = 0 or 1st row set by manually
        if(arr[0] <= target) dp[0][arr[0]] = 1; 
        if(arr[0] == 0) dp[0][0] = 2;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<= target; j++){
                int notPick = dp[i-1][j];// taking previous only
                //calculate with pick this index
                int pick = 0;
                if(arr[i] <= j) pick = dp[i-1][j-arr[i]];
                
                dp[i][j] = notPick + pick; // stored total ans for individul cell
            }
        }
        
        return dp[n-1][target];
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
Space Complexity: O(n * target) + O(n)*/