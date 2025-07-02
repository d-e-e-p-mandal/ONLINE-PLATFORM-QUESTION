// Leetcode : 1463 : Cherry Pickup 2 : Dynamic Programming : Memoisation (Top-Down)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        //use dp to store only previous row
        vector<vector<int>> dp(c, vector<int>(c));

        //base case : all possible outcome : (r-1) row calculation
        for(int c1 =0; c1<c; c1++) {
            for(int c2=0; c2<c; c2++) {
                if(c1 == c2) dp[c1][c2] = grid[r-1][c1];//grid[r-1][c2];
                else dp[c1][c2] = grid[r-1][c1] + grid[r-1][c2];
            }
        }

        // bottom up : each row calculation
        for(int row = r-2; row>=0; row--) {
            vector<vector<int>> currDp(c,vector<int>(c)); //temporary datastructure
            for(int c1=0; c1<c; c1++) {
                for(int c2=0; c2<c; c2++) {
                    int curr;
                    if(c1 == c2) curr = grid[row][c1];  //if they are same index 
                    else curr = grid[row][c1] + grid[row][c2];

                    int maxi = INT_MIN;
                    //all possible moves
                    for(int i=-1; i<=1; i++) {
                        for(int j=-1; j<=1; j++) {
                            int prev = ((c1+i >=0 && c1+i < c && c2+j >=0 && c2+j < c) ? dp[c1+i][c2+j] : -1e8); 
                            maxi = max(maxi,prev);
                        }
                    }
                    currDp[c1][c2] = curr + maxi; 
                }
            }
            dp = currDp; // store only previous row, so swaping it
        }

        return dp[0][c-1];
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