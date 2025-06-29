// Leetcode : 63 : Unique Paths 2 : Dynamic Programming : Tabulation (Bottom-Up) 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0)); //dp to store result of each cell

        // Iteration : Tabulation
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0; //if obsticale
                else if(i==0 && j == 0) dp[i][j] = 1; //if 1st cell
                else {
                    //calculation of (i,j) from previous
                    int x = (i>0) ? dp[i-1][j] : 0;
                    int y = (j>0) ? dp[i][j-1] : 0;
                    dp[i][j] = x+y;
                }
                
            }
        }

        return dp[r-1][c-1]; //res
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