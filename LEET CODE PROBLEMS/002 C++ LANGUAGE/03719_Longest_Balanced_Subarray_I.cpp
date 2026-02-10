// LeetCode : 3719 : Longest Balanced Subarray I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest subarray where
    // number of distinct odd elements == number of distinct even elements
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int window_size = 0;

        // Fix starting index
        for (int i = 0; i < n - 1; i++) {

            unordered_set<int> odd;
            unordered_set<int> even;

            // Extend ending index
            for (int j = i; j < n; j++) {

                if (nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);

                // Check balance condition
                if (odd.size() == even.size())
                    window_size = max(window_size, j - i + 1);
            }
        }

        return window_size;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.longestBalanced(nums) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
6
1 2 3 4 5 6

Sample Output:
6

Explanation:
Distinct odd numbers = {1,3,5}
Distinct even numbers = {2,4,6}
Both sets have equal size (3).

-----------------------------------------
Time Complexity:
O(n^2)
Reason:
Two nested loops over the array.
unordered_set operations are O(1) on average.

-----------------------------------------
Space Complexity:
O(n)
Reason:
Sets store distinct odd and even elements.

-----------------------------------------
*/