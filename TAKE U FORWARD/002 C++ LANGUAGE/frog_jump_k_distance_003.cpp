#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int frogJump(int n, vector<int>& heights) {
        int prev1 = 0; // cost to reach step 0
        int prev2 = 0; // cost to reach step -1 (boundary)
        
        for(int i = 1; i < n; i++) {
            int jumpOne = prev1 + abs(heights[i] - heights[i - 1]);
            int jumpTwo = INT_MAX;

            if(i > 1)
                jumpTwo = prev2 + abs(heights[i] - heights[i - 2]);

            int curr = min(jumpOne, jumpTwo);

            // Update prevs
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> heights = {10, 30, 40, 20}; // Example input
    int n = heights.size();

    int result = sol.frogJump(n, heights);

    cout << "Minimum energy required: " << result << endl;

    return 0;
}

/*OUTPUT : Minimum energy required: 30 */