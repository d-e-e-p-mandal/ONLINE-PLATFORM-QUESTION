// GEEK FOR GEEKS : Frog Jump : use of recursiion

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
  public:
    int frogJump(vector<int>&height, int index, vector<int> &dp){
        // base case
        if(index == 0) return 0;
    
        int fs = frogJump(height, index - 1, dp) + abs(height[index] - height[index - 1]);
        
        int ls = INT_MAX;
        if(index>1)
            ls = frogJump(height, index - 2, dp) + abs(height[index] - height[index - 2]);
    
        return min(fs,ls);
    }
    
    int minCost(vector<int>& height) {
        vector<int>dp(height.size(),-1);
        
        return frogJump(height,height.size()-1,dp);
    }
};
    

int main() {
    Solution sol;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    
    cout << "Minimum cost: " << sol.minCost(height) << endl;

    return 0;
}

/*OUTPUT : Minimum cost: 40 */