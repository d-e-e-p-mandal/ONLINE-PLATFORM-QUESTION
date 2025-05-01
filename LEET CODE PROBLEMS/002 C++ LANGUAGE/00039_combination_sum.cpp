// Leetcode : 39 : Combination sum
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void combSum(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int target, int index) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            combSum(candidates, ans, ds, target - candidates[index], index); // reuse allowed
            ds.pop_back();
        }

        combSum(candidates, ans, ds, target, index + 1); // skip to next
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combSum(candidates, ans, ds, target, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
/*
class Solution {
public:
    void combSum(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int target, int index) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                ds.push_back(candidates[i]);
                combSum(candidates, ans, ds, target - candidates[i], i); // reuse allowed
                ds.pop_back(); // backtrack
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combSum(candidates, ans, ds, target, 0);
        return ans;
    }
};
*/
/* OUTPUT : 
Combinations that sum to 7:
[2, 2, 3]
[7]
*/