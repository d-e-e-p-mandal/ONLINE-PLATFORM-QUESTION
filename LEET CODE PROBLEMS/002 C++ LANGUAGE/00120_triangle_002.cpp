// Leetcode : 120 : Triangle : Dynamic Programming : Memoisation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(i==0 && j ==0)dp[0][0] = triangle[0][0];
                else{
                    int up = triangle[i][j] + (( i != j) ? dp[i-1][j] : 1e9+7);

                    int upD = triangle[i][j] + ((i>0 && j>0) ? dp[i-1][j-1] : 1e9+7);

                    dp[i][j] = min(up, upD);

                    
                }

                if( i == n-1)mini = min(mini,dp[i][j]);
            }

            
        }
        return mini;
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