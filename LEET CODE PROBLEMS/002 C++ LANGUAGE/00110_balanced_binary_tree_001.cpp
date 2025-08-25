// LeetCode : 110 : Balanced Binary Tree : Brute Force

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
    int height(TreeNode* root) { // function of finding height of tree
        if(root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right)); // max of left and right
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftHeight = height(root->left); // height of left
        int rightHeight = height(root->right); // height of right
        // check balanced tree condition
        if(abs(leftHeight - rightHeight) > 1) return false; 
        // check also all sub-tree
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};

int main() {
    Solution sol;

    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if(sol.isBalanced(root)) {
        cout << "Tree is balanced ✅" << endl;
    } else {
        cout << "Tree is not balanced ❌" << endl;
    }

    return 0;
}
/*OUTPUT :Tree is balanced ✅ */
/*Time Complexity: O(n^2), Space Complexity: O(h) → O(n) in worst case (including recursion space)*/