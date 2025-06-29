// Leetcode : 64 : Minimum Path Sum : Dynamic Programming : Tabulation (Bottom-Up) : Space Optimised
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int r = grid.size(); //no of rows
        int c = grid[0].size(); //no of columns

        vector<int>dp(c,-1); // data structure to store only previous
 
        for(int i=0; i<r; i++){
            vector<int> curr(c);
            for(int j=0; j<c; j++){
                if(i==0 && j==0)curr[j] = grid[0][0]; //if it is index (0,0)
                else{
                    //to ignore out of boundary case assign large number
                    int up =  ((i>0) ? dp[j] : 1e9 + 7); 
                    int down =  ((j>0) ? curr[j-1] : 1e9 + 7);
                    
                    curr[j] =grid[i][j] +  min(up,down); // store min value
                }
            }
            dp = curr;
        }
        return dp[c-1];
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution sol;
    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}

/*Output : Minimum Path Sum: 7 */

/*Time Complexity: O(m * n)
Space Complexity: O( n)*/