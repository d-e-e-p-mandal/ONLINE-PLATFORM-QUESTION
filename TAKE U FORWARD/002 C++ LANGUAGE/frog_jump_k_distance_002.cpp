#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int frogJump(int n, vector<int>& heights, int k) {
        vector<int> dp(n, 0);
        dp[0] = 0; // base case: starting at step 0

        for(int i = 1; i < n; i++) {
            int minCost = INT_MAX;

            for(int j = 1; j <= k; j++) {
                if(i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minCost = min(minCost, jump);
                }
            }

            dp[i] = minCost; // store min cost to reach step i
        }

        return dp[n - 1]; // final step
    }
};

int main() {
    Solution sol;

    vector<int> heights = {10, 30, 40, 50, 20}; // Example input
    int n = heights.size();
    int k = 3;

    int result = sol.frogJump(n, heights, k);

    cout << "Minimum energy required: " << result << endl;

    return 0;
}

/*Output : Minimum energy required: 30 */