// LeetCode : 3379. Transformed Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // For each index i, compute the transformed index
        for (int i = 0; i < n; i++) {

            // Calculate valid index using modulo (handles negative values)
            int x = ((nums[i] % n) + n + i) % n;

            // Assign value from transformed index
            result[i] = nums[x];
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    vector<int> ans = obj.constructTransformedArray(nums);

    for (int x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}

/*
-----------------------------------------
Sample Input:
5
3 -2 1 1 -3

Sample Output:
1 1 -2 -3 3

Explanation:
For each index i:
i=0 → (0 + 3) % 5 = 3 → nums[3] = 1
i=1 → (1 - 2) % 5 = 4 → nums[4] = -3
i=2 → (2 + 1) % 5 = 3 → nums[3] = 1
i=3 → (3 + 1) % 5 = 4 → nums[4] = -3
i=4 → (4 - 3) % 5 = 1 → nums[1] = -2

-----------------------------------------
Time Complexity:
O(n)
Reason:
Single pass through the array.

Space Complexity:
O(n)
Reason:
Extra array used to store transformed result.

-----------------------------------------
*/