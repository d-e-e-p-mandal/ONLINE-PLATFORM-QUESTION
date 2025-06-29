// Leetcode : 64 : Minimum Path Sum : Dynamic Programming : Memoisation (Top-Down)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp){

        if( r==0 && c == 0) return grid[r][c]; // for (0,0) index, base case
        if(r < 0 || c < 0) return 1e9 + 7; //to ignore out of boundary case assign large number

        if(dp[r][c] != -1) return dp[r][c]; //if already calculated, calculate only once

        int up = grid[r][c] + minCost(grid, r-1, c, dp); // current + previous calculate (up)
        int left = grid[r][c] + minCost(grid, r, c-1, dp); //current + previous calculate (left)
        
        return dp[r][c] = min(up, left); //take minimum
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(); //no of rows
        int c = grid[0].size(); //no of columns

        vector<vector<int>> dp(r, vector<int>(c, -1)); //datastructure

        return minCost(grid, r-1, c-1, dp);
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
Space Complexity: O(m * n)*/