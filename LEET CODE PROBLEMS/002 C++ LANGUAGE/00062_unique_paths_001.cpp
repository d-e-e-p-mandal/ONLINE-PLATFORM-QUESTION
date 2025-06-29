//LeetCode : 62 : Unique Path : Dynamic Programming : Memoization

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int noOfPaths(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1; //top-down approach if it reach at (0,0) index retun 1 ways (1 count)
        if(m < 0 || n < 0) return 0; // if it out of bond

        if(dp[m][n] != -1) return dp[m][n]; //if it already calculated

        int up = noOfPaths(m-1, n, dp); //move up
        int left = noOfPaths(m, n-1, dp); //move left

        return dp[m][n] = up+left; //return total ways
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1)); //2D datastructure

        return noOfPaths(m-1,n-1,dp);
    }
};

int main() {
    Solution sol;
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}