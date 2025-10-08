// Leetcode : 611 : Valid Triangle Number : Brute Force

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n < 3) return 0; // fewer than 3 numbers can't form a triangle

        sort(nums.begin(), nums.end()); // sort for triangle inequality

        // Choose two sides nums[i], nums[j]
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                // Find the farthest k such that nums[i] + nums[j] > nums[k]
                for (int k = n - 1; k > j; k--) {
                    if (nums[i] + nums[j] > nums[k]) {
                        ans += k - j; // all indices between j+1 and k are valid
                        break; // stop, since array is sorted
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 4};

    int result = sol.triangleNumber(nums);
    cout << "Number of valid triangles: " << result << endl;

    return 0;
}

/*
Example Output:
Number of valid triangles: 3

Valid combinations:
- (2, 3, 4)
- (2, 3, 4) [other 2]
- (2, 2, 3)

-----------------------
Time Complexity:
- Sorting: O(n log n)
- Double loop (i, j): O(n^2)
- Inner loop with break: Worst O(n), but usually breaks early.
=> Overall: O(n^2)

Space Complexity:
- O(1) extra (in-place sort).
*/