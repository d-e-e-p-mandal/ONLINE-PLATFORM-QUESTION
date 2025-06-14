// GGG : Frog Jump : Memoization (top - down approach)
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
  public:
    int frogJump(vector<int>& height, int index, vector<int> &dp) {
        // base case
        if(index == 0) return 0;
        
        if(dp[index] != -1) return dp[index];
    
        int fs = frogJump(height, index - 1, dp) + abs(height[index] - height[index - 1]);
        
        int ls = INT_MAX;
        if(index > 1)
            ls = frogJump(height, index - 2, dp) + abs(height[index] - height[index - 2]);
        
        // store in dp
        dp[index] = min(fs, ls);
        
        return dp[index];
    }
    
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);
        return frogJump(height, height.size() - 1, dp);
    }
};

int main() {
    Solution sol;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    
    cout << "Minimum cost: " << sol.minCost(height) << endl;

    return 0;
}

/*OUTPUT : Minimum cost: 40 */