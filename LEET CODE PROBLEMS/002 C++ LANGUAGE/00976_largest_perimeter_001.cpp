// Leetcode : 976 : Largest Perimeter Triangle : Brute Force Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the largest perimeter of a valid triangle
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end()); // Sort ascending
        int maxPerimeter = 0;

        // Fix the largest side nums[k]
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // Valid triangle found
                    maxPerimeter = max(maxPerimeter, nums[i] + nums[j] + nums[k]);
                }
                i++; // move left pointer
            }
        }

        return maxPerimeter;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 2};

    int result = sol.largestPerimeter(nums);
    cout << "Largest Perimeter: " << result << endl;

    return 0;
}

/*
Example Output:
Largest Perimeter: 5

-----------------------
Time Complexity:
- Sorting: O(n log n)
- Nested loop: O(n^2) in worst case
- Total: O(n^2)

Space Complexity:
- O(1), ignoring sort overhead.
*/