// LeetCode : 110 : Balanced Binary Tree : Optimal Solution

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
    int checkBalance(TreeNode* root) { // check balance using height : if it not balance return -1 and if balance return height
        // base case : if root is null height 0
        if(root == nullptr) return 0;
        // check left sub-tree : if not balance return -1
        int leftHeight = checkBalance(root->left);
        if(leftHeight == -1) return -1;
        // check right subtree : if not balance return -1
        int rightHeight = checkBalance(root->right);
        if(rightHeight == -1) return -1;
        // check balance : each sub-tree
        if(abs(leftHeight - rightHeight) > 1) return -1;
        // if balance return height
        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {

        int height = checkBalance(root); // if balance then height = height of tree, if not then it is -1 

        return (height == -1 ? false : true);
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
/*Time Complexity: O(n), Space Complexity: O(h) → O(n) in worst case (including recursion space)*/