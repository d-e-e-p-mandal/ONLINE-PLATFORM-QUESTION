// Leetcode : 198 : House Robber : Dynamic Programming : (Tabulation (Bottom-Up)) : Space Optimisation
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //(Tabulation (Bottom-Up)) : Space optimisation
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int curr;
        int prev1 = nums[0];
        int prev2 = 0; // at starting point (index < 0 : for boundary case) return 0

        for(int i = 1; i < n; i++) {
            curr = max((nums[i] + prev2), prev1);
            // update value
            prev2 = prev1;
            prev1 = curr; // prev1 is update to curr we can return prev1
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> houses = {2, 7, 9, 3, 1}; // Example input
    int result = sol.rob(houses);        // Call rob function

    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
/*Output : Maximum amount that can be robbed: 12 */
/*Time Complexity : O(N)
Space Complexity : O(1)*/