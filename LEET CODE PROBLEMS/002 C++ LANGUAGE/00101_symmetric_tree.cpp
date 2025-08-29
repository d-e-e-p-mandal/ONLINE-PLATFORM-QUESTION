// LeetCode : 101 : Symmetric Tree : Optimal Solution
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
    bool findSymmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        //base case : if both left and right null true and if any one of them null then return false
        if(leftRoot == nullptr && rightRoot == nullptr) return true; 
        if(leftRoot == NULL || rightRoot == NULL) return false;
        // check equal value
        if(leftRoot->val != rightRoot->val) return false;
        // recursive check : leftRoot->left == rightRoot->right && leftRoot -> right == rightRoot->left
        return (findSymmetric(leftRoot->left, rightRoot->right) && findSymmetric(leftRoot->right, rightRoot->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
    // constraints : atleast one node
    // match left part and right part of tree
     return (findSymmetric(root->left, root->right));   
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
        Symmetric
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSymmetric(root) ? "Tree is Symmetric" : "Tree is Not Symmetric") << endl;

    return 0;
}

/*
Output:
Tree is Symmetric

Time Complexity: O(N)  // every node visited once
Space Complexity: O(H) // recursive stack, H = height of tree
*/