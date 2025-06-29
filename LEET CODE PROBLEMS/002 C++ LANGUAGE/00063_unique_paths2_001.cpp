// Leetcode : 63 : Unique Paths 2 : Dynamic Programming : Memoization (Top-Down) :
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalPaths(vector<vector<int>> arr, int r, int c, vector<vector<int>> &dp){
        if(r < 0 || c < 0) return 0; // out of boundary
        if(arr[r][c] == 1) return 0;  // if obsticale
        if(r == 0 && c == 0) return 1;  //reach (0,0) index 

        if(dp[r][c] != -1) return dp[r][c];

        int x = totalPaths(arr, r - 1, c, dp); //previous row calculate
        int y = totalPaths(arr, r, c - 1, dp); //previous column calculate
        
        return dp[r][c] = x+y;  //store and return
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
        int r = obstacleGrid.size(); //row
        int c = obstacleGrid[0].size(); //column

        vector<vector<int>>dp(r,vector<int>(c,-1)); // to store the result

        return totalPaths(obstacleGrid, r-1, c-1, dp);
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    cout << "Enter the grid (" << r << "x" << c << ", 0 for free cell, 1 for obstacle):\n";
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.uniquePathsWithObstacles(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}

/*Output :
Enter number of rows and columns: 3 3
Enter the grid (3x3, 0 for free cell, 1 for obstacle):
0 0 0
0 1 0
0 0 0

Number of unique paths: 2 */

/*Time Complexity: O(m * n)
Space Complexity: O(m * n)*/