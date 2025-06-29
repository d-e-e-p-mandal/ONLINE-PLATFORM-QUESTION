// Leetcode 46 : Permutations : more optimise : swap function use
#include <iostream>
#include <vector>
using namespace std;

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
            swap(nums[i],nums[index]); // reverse swap
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res; // to store answer

        backtrack(nums, res, 0);

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