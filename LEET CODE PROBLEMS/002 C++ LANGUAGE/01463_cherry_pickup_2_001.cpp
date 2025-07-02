// Leetcode : 1463 : Cherry Pickup 2 : Dynamic Programming : Memoisation (Top-Down)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int pick(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp){
        if(c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size()) return -1e8;
        if(r == grid.size()) return 0;

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int maxi = INT_MIN;
        int curr;
        if(c1 == c2) curr = grid[r][c1];
        else curr = grid[r][c1] + grid[r][c2];

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int prev = pick(grid, r+1, c1+i, c2+j, dp);
                maxi = max(maxi, prev);
            }
        }
        return dp[r][c1][c2] = curr + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return pick(grid, 0, 0, c-1, dp);
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter grid values:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.cherryPickup(grid);
    cout << "Maximum cherries collected: " << result << endl;

    return 0;
}

/*Output : Enter number of rows and columns: 3 3
Enter grid values:
1 2 3
0 1 4
7 6 5

Maximum cherries collected: 24 */

/*Time Complexity: O(r * c²)
Space Complexity: O(r * c²) (DP array) + O(r) (recursion stack space)*/