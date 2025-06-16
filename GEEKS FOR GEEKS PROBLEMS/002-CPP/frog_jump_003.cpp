// GGG : Frog Jump : Tabulation (buttom up approach)

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int prev1,prev2;
        prev1 = prev2 = 0;
        
        for(int i = 1; i< height.size(); i++){
            int fs = prev1 + abs( height[i] - height[i-1]);
            
            int ls = INT_MAX;
            if(i>1) ls = prev2 + abs(height[i] - height[i-2]);
            
            prev2 = prev1;
            prev1 = min(fs,ls);
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    
    cout << "Minimum cost: " << sol.minCost(height) << endl;

    return 0;
}

/*
int minCost(vector<int>& height) {

        vector<int>dp(height.size(),0);
        dp[0] = 0;

        for(int i = 1; i< height.size(); i++){
            int fs = dp[i-1] + abs( height[i] - height[i-1]);
            
            int ls = INT_MAX;
            if(i>1) ls = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(fs,ls);
        }
        return dp[height.size() - 1];
    }
*/

/*OUTPUT : Minimum cost: 40 */