// Leetcode : 2294 : Partition Array Such That Maximum Difference is K
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int noOfPartition = 0;

        sort(nums.begin(),nums.end()); //sort the array

        int pick = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] - pick > k){ //if greater than k then take another subsequence
                noOfPartition++;
                pick = nums[i];
            }
        }

        return noOfPartition + 1; //adding last subsequence
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 6, 1, 9, 12};
    int k = 3;

    int result = sol.partitionArray(nums, k);
    cout << "Number of partitions: " << result << endl;

    return 0;
}

/*Output : Number of partitions: 3 */
/*Time complexity : O(NLogN)
Space complexity : O(1) */