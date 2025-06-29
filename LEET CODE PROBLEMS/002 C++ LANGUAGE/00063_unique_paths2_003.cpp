// Leetcode : 63 : Unique Paths 2 : Dynamic Programming : Tabulation (Bottom-up) Spaced optimised
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<int>dp(c,0); //dp to store result of each cell

        // Iteration : Tabulation
        for(int i=0; i<r; i++){
            vector<int>curr(c);
            for(int j=0; j<c; j++){
                if(obstacleGrid[i][j] == 1) curr[j] = 0; //if obsticale
                else if(i==0 && j == 0) curr[j] = 1; //if 1st cell
                else {
                    //calculation of (i,j) from previous
                    int up = (i>0) ? dp[j] : 0; // up means previous stored in dp
                    int left = (j>0) ? curr[j-1] : 0; // left stored in current
                    curr[j] = up+left;  
                }
            }
            dp = curr; //update dp (current convert in previous)
        }

        return dp[c-1]; //res
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