// Leetcode : 120 : Triangle : Dynamic Programming : Memoisation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pathSum(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp){
        if(r== triangle.size() - 1) return triangle[r][c];

        if(dp[r][c] != 1e9+7) return dp[r][c];

        int down = triangle[r][c] + pathSum(triangle, r+1, c, dp);
        int diagonal = triangle[r][c] + pathSum(triangle, r+1, c+1, dp);

        return dp[r][c] = min(down, diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9+7));
        
        return pathSum(triangle, 0, 0,dp);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int result = sol.minimumTotal(triangle);
    cout << "Minimum Total Path Sum: " << result << endl;

    return 0;
}

