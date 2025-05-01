// Leetcode : 78 : subsets
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& ds, int index) {
        if (index == nums.size()) {
            result.push_back(ds);
            return;
        }

        // Exclude the current element
        backtrack(nums, result, ds, index + 1);

        // Include the current element
        ds.push_back(nums[index]);
        backtrack(nums, result, ds, index + 1);
        ds.pop_back(); // Backtrack
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        backtrack(nums, result, ds, 0);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3}; // Example input
    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
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

/*     void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& ds, int index) {
        if (index == nums.size()) {
            result.push_back(ds);
            return;
        }

        // Include the current element
        ds.push_back(nums[index]);
        backtrack(nums, result, ds, index + 1);

        // Exclude the current element
        ds.pop_back(); // Backtrack
        backtrack(nums, result, ds, index + 1);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        backtrack(nums, result, ds, 0);
        return result;
    }
};
*/

/*
void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>ds, int index,int n){
        result.push_back(ds);
   
        for(int i = index; i < n; i++){
            ds.push_back(nums[i]);
            backtrack(nums,result, ds , i+1 ,n);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;

        vector<int> ds;

        backtrack(nums,result, ds , 0,n);

        return result;
    }
};*/

/*
void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>ds, int index,int n){
   
        for(int i = index; i < n; i++){
            ds.push_back(nums[i]);
            backtrack(nums,result, ds , i+1 ,n);
            ds.pop_back();
        }
        result.push_back(ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;

        vector<int> ds;

        backtrack(nums,result, ds , 0,n);

        return result;
    }
};
*/

/* OUTPUT :
[]
[3]
[2]
[2, 3]
[1]
[1, 3]
[1, 2]
[1, 2, 3]
*/