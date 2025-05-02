// Leetcode 46 : Permutations
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& ds, vector<vector<int>>& res, vector<int>& hash) {
        if (ds.size() == nums.size()) { // base case
            res.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash[i] == 0) { // if not added then add
                ds.push_back(nums[i]);  // add
                hash[i] = 1;             // mark
                backtrack(nums, ds, res, hash);
                ds.pop_back();          // remove
                hash[i] = 0;            // unmark
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> hash(nums.size(), 0); // using hash map solution
        vector<int> ds;
        backtrack(nums, ds, res, hash);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = sol.permute(nums);

    cout << "Permutations:" << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
/* more optimise : swap function use
class Solution {
    public :
    void backtrack(vector<int>&nums,vector<vector<int>>&res, int index){
        if(index == nums.size()){ //base case
            res.push_back(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[index],nums[i]); //swap
            backtrack(nums, res, index+1);
            swap(nums[i],nums[index]); // revese swap
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res; // to store answer

        backtrack(nums,res,0);

        return res;
    }
};*/

/*Time complexity : O(n! * n)*/
/*Display : 
Permutations:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/