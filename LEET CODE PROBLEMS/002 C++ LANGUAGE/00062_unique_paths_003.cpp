//LeetCode : 62 : Unique Path : Dynamic Programming : Tabulation : Space Optimisation
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int>dp(n); // col size 1D array : to store previous
        dp[0] = 1;// initilize (0,0) index by 1

        // iteration each cell
        for(int i=0; i<m; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){
                if (i == 0 && j == 0)
                    curr[j] = 1;  // starting point
                else {
                    int up = ((i>0) ? dp[j] : 0);          // from the cell above
                    int left = (j > 0) ? curr[j - 1] : 0;  // from the cell to the left
                    curr[j] = up + left;
                }
            }
            dp = curr;
        }

        return dp[n-1];
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
