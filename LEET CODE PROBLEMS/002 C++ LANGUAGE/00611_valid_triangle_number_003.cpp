// Leetcode : 611 : Valid Triangle Number : Optimal Solution (Binary Search)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // less than 3 sides can't form a triangle

        sort(nums.begin(), nums.end()); // sort sides
        int ans = 0;

        // Fix the largest side nums[k]
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // If nums[i] + nums[j] > nums[k], 
                    // then all elements from i..j-1 with nums[j] are valid
                    ans += j - i;
                    j--; // try smaller second side
                } else {
                    i++; // increase smaller side
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

Explanation:
Possible triangles:
- (2, 3, 4)
- (2, 3, 4)  [other 2]
- (2, 2, 3)

-----------------------
Time Complexity:
- Sorting: O(n log n)
- Two-pointer scan: O(n^2)
=> Overall: O(n^2)

Space Complexity:
- O(1) extra space (in-place sort).
*/