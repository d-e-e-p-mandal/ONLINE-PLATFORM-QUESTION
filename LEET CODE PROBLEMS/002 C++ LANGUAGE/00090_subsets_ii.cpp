// Leetcode : 90 : Subsets 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int index) {
        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i - 1] == nums[i]) continue;

            ds.push_back(nums[i]);
            backtrack(nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, ds, 0);
        return ans;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {1, 2, 2};

    // Get subsets
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    // Print result
    cout << "Unique subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
/*
class Solution {
public:
    void backtrack(vector<int>&nums, set<vector<int>>&ans, vector<int>ds, int index) {
        if(index == nums.size()){
            ans.insert(ds);
            return;
        }

        backtrack(nums, ans, ds, index+1);
        ds.push_back(nums[index]);
        backtrack(nums, ans, ds, index+1);
        ds.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        
        backtrack(nums, ans, ds, 0);//forward

        return vector<vector<int>>(ans.begin(),ans.end());
    }
};*/

/*
Unique subsets:
[]
[1]
[1, 2]
[1, 2, 2]
[2]
[2, 2]
*/