// LeetCode : 124 : Binary Tree Maximum Path Sum : Optimal Solution

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
    int maximumSum(TreeNode* root, int* maxSum) {
        // base case : add 0 (addition identity) when it reach null
        if(root == nullptr) return 0;
        // when it backtracking if left or right sum is negative -ve, don't comsider left and right subtree, take sum as 0 (neglate)
        int leftSum = 0;
        leftSum = max(leftSum, maximumSum(root->left, maxSum));
        int rightSum = 0;
        rightSum = max(rightSum, maximumSum(root->right, maxSum));
        // taking maximum of subtree
        *maxSum = max(*maxSum, root->val + leftSum + rightSum);
        // return maximum of path
        return root->val + max(leftSum ,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        // taking min value
        int maxSum = INT_MIN;
        // send the address of maxSum to update in memory
        maximumSum(root, &maxSum);
        
        return maxSum;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Example tree:
                 -10
                 /  \
                9   20
                   /  \
                  15   7
        Expected max path sum = 42 (15 + 20 + 7)
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum = " << sol.maxPathSum(root) << endl;

    return 0;
}

// Output: Maximum Path Sum = 42
    // Time Complexity: O(N), Space Complexity: O(H) where H = height of tree (recursion stack)