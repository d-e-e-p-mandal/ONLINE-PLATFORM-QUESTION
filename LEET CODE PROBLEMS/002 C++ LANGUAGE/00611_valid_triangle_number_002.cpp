// Leetcode : 611 : Valid Triangle Number : Brute Force

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n < 3) return 0; // fewer than 3 sides can't form a triangle

        sort(nums.begin(), nums.end()); // sort for triangle inequality

        // Try all triplets (i, j, k)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check triangle inequality: nums[i] + nums[j] > nums[k]
                    if (nums[i] + nums[j] > nums[k]) {
                        ans++;
                    } else {
                        // Since array is sorted, further k will only be larger → break
                        break;
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
- (2, 2, 3)
- (2, 3, 4)
- (2, 3, 4)  [other 2]

-----------------------
Time Complexity:
- Sorting: O(n log n)
- Triple loop: O(n^3) in worst case,
  but because of "break", often closer to O(n^2) in practice.
=> Worst case: O(n^3)

Space Complexity:
- O(1) extra (in-place sort).
*/