// LEETCODE : 40 : COMBINATION SUM 2 :

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>&candidates,int target, vector<vector<int>>&ans, int index, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i <candidates.size(); i++){
            if(i > index && candidates[i-1] == candidates[i])continue;
            if (candidates[i] > target) break;

            ds.push_back(candidates[i]);
            backtrack(candidates,target - candidates[i],ans,i+1,ds);
            ds.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, ans, 0,ds);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& comb : result) {
        cout << "[";
        for (size_t i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
/*
void backtrack(vector<int>&candidates,int target, vector<vector<int>>&ans, int index, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(index == candidates.size())return;
        if (candidates[index] > target) return;


        for(int i = index; i <candidates.size(); i++){
            if(i > index && candidates[i-1] == candidates[i])continue;
            

            ds.push_back(candidates[i]);
            backtrack(candidates,target - candidates[i],ans,i+1,ds);
            ds.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, ans, 0,ds);
        return ans;
    }
};
*/


/*
Brute Force soln:
class Solution {
public:
    void bruteForce(vector<int>& candidates, int target, int index, vector<int>& ds, set<vector<int>>& uniqueComb) {
        if (target == 0) {
            uniqueComb.insert(ds); // Automatically skips duplicates
            return;
        }

        if (target < 0 || index == candidates.size()) return;

        // Include current element
        ds.push_back(candidates[index]);
        bruteForce(candidates, target - candidates[index], index + 1, ds, uniqueComb);
        ds.pop_back();

        // Exclude current element
        bruteForce(candidates, target, index + 1, ds, uniqueComb);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // optional for canonical ordering in set
        set<vector<int>> uniqueComb;
        vector<int> ds;
        bruteForce(candidates, target, 0, ds, uniqueComb);

        // Convert set to vector
        return vector<vector<int>>(uniqueComb.begin(), uniqueComb.end());
    }
};
*/
/*OUTPUT : 
Unique combinations that sum to 8:
[1, 1, 6]
[1, 2, 5]
[1, 7]
[2, 6]
*/