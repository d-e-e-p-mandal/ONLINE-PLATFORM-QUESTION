// Leetcode : 213 : House Robber2 : Dynamic Programming : (Tabulation (Bottom-Up)) : Space Optimisation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<int> &nums, int start, int end) {

        // using two variable two store previous data
        int prev2 = 0;
        int prev1 = nums[start];

        for(int i=start + 1; i<end; i++) {
            int curr = max(nums[i] + prev2, prev1); //max of adjacent
            //update value
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];

        // circular: divide into two parts (1st and last, pick only one at a time, and max of them)
        return max(maximumAmount(nums, 0 , n-1), maximumAmount(nums, 1 , n));
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the money in each house: ";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}


/*Output : 
Enter number of houses: 4
Enter the money in each house: 2 3 2 3 
Maximum amount that can be robbed: 5
*/

/*Time Complexity : O(N)
Space Complexity : O(N)*/