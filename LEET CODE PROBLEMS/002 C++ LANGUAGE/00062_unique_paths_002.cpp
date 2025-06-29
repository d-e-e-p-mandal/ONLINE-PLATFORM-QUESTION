////LeetCode : 62 : Unique Path : Dynamic Programming : Tabulation
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;// initilize (0,0) index by 1

        // iteration each cell
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( i != 0 || j != 0){ // if it is not 1st cell
                    int up = ((i > 0) ? dp[i-1][j] : 0); // if (i-1) out of bound it will be 0 , means no up step
                    int left = ((j>0) ? dp[i][j-1] : 0);// if (j-1) out of bound it will be 0 , means no left step
                    dp[i][j] = up + left; //stored total step
                }
            }
        }

        return dp[m-1][n-1];
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
