// Leetcode : 931 : Minimum Falling Path Sum : Dynamic Programming : Tabulation : (Bottom Up)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public: //Tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n));
        //base case : copy 1st row (r == 0) in dp
        for(int c=0; c<n; c++) dp[0][c] = matrix[0][c];
        //interation
        for(int r=1; r<n; r++){ // (r==0) already calculated
            for(int c=0; c<n; c++){
                int down = matrix[r][c] + dp[r-1][c]; 
                int leftDiagonal = matrix[r][c] + ((c>0) ? dp[r-1][c-1] : 1e8);
                int rightDiagonal = matrix[r][c] + ((c<n-1) ? dp[r-1][c+1] : 1e8);

                dp[r][c] = min(down, min(leftDiagonal, rightDiagonal)); //stored in dp
                //if(r == n-1) mini = min(mini, dp[r][c]); // if (no of row > 1) this condition used to find min 
            }
        }
        //find min
        for(int c=0; c<n; c++){
            mini = min(mini, dp[n-1][c]);
        }
    
        return mini;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum Falling Path Sum: " << result << endl;

    return 0;
}

/*Output : Minimum Falling Path Sum: 13 */

/*Time Complexity: O(n²)
Space Complexity: O(n²)*/