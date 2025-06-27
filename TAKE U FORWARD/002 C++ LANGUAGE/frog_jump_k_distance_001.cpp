#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minEnergy(int index, vector<int>& heights, int k, vector<int>& dp) {
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];

        int minCost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(index - j >= 0) {
                int jump = minEnergy(index - j, heights, k, dp) + abs(heights[index] - heights[index - j]);
                minCost = min(minCost, jump);
            }
        }

        return dp[index] = minCost;
    }

    int frogJump(int n, vector<int>& heights, int k) {
        vector<int> dp(n, -1);
        return minEnergy(n - 1, heights, k, dp);
    }
};

int main() {
    Solution sol;

    int n = 5;
    int k = 3;
    vector<int> heights = {10, 30, 40, 50, 20};

    int result = sol.frogJump(n, heights, k);

    cout << "Minimum energy required: " << result << endl;

    return 0;
}

/* Minimum energy required: 30 */