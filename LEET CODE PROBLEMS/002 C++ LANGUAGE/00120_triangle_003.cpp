// Leetcode : 120 : Triangle : Dynamic Programming : Memoisation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Start from the last row (base case)
        vector<int> dp(triangle[n - 1]);

        // Bottom-up DP from second-last row to top
        for (int i = n - 2; i >= 0; i--) {
            vector<int> currRow(i + 1);
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j + 1];
                currRow[j] = min(down, diag);
            }
            dp = currRow; // Move to upper row
        }

        return dp[0]; // Final answer at the top
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