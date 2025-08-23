// Leetcode : 113 : Path Sum 2 :

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void findTarget(TreeNode* root, int targetSum, vector<int> &temp, vector<vector<int>> &ans) {
        // base case : check the leaf code and also reach its target
        if(root->left == NULL && root->right == NULL) {
            if(root->val == targetSum) {
                temp.push_back(root->val); // push the leaf node i
                ans.push_back(temp);     // store the ans
                temp.pop_back();     // remove : backtrack
            }   
            return;
        }
        
        temp.push_back(root->val); // take ans answer
        if(root ->left) findTarget(root->left, targetSum - root->val, temp, ans); // go left

        if(root ->right) findTarget(root->right, targetSum - root->val, temp, ans); // go right
        // backtrack
        temp.pop_back();     // remove form answer
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;    // datastructure

        if(root == NULL) return ans; // if no node exist

        findTarget(root, targetSum, temp, ans);
        
        return ans;
    }
};

int main() {
    /*
        Example Tree:
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \    / \
          7    2  5   1

        targetSum = 22
        Expected paths:
        [5,4,11,2]
        [5,8,4,5]
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";
    for(auto &path : result) {
        cout << "[ ";
        for(int val : path) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}

/* OUTPUT :
Paths with sum 22:
[ 5 4 11 2 ]
[ 5 8 4 5 ]
*/

/*Time: O(N²), Space: O(N² + H(recurssion space, Height of the tree))*/
