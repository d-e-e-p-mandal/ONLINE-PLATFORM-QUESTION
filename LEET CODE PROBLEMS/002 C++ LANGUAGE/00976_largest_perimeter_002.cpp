// Leetcode : 976 : Largest Perimeter Triangle : Optimal Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the largest perimeter of a valid triangle
    int largestPerimeter(vector<int>& nums) {
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Check consecutive triplets
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                // Found a valid triangle
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        // No valid triangle found
        return 0;
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
- O(n log n), due to sorting.

Space Complexity:
- O(1), ignoring sort overhead.
*/