// Leetcode : 931 : Minimum Falling Path Sum : Dynamic Programming : Tabulation : (Bottom Up)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public: //Tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int mini = INT_MAX;
        vector<int> prev(matrix[0]);//base case : copy 1st row (r == 0) in prev , we don't need extra loop // for(int c=0; c<n; c++) prev[0][c] = matrix[0][c];
        //iteration
        for(int r=1; r<n; r++){ // (r==0) already calculated
            vector<int>curr(n);
            for(int c=0; c<n; c++){
                int down = matrix[r][c] + prev[c]; 
                int leftDiagonal = matrix[r][c] + ((c>0) ? prev[c-1] : 1e8);
                int rightDiagonal = matrix[r][c] + ((c<n-1) ? prev[c+1] : 1e8);

                curr[c] = min(down, min(leftDiagonal, rightDiagonal)); //stored in prev
                //if(r == n-1) mini = min(mini, prev[r][c]); // if (no of row > 1) this condition used to find min 
            }
            prev = curr;
        }
        //find min
        for(int c=0; c<n; c++){
            mini = min(mini, prev[c]);
        }
    
        return mini;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum Falling Path Sum: " << result << endl;

    return 0;
}

/*Output : Minimum Falling Path Sum: 13 */

/*Time Complexity: O(N²)
Space Complexity: O(N)*/