// LeetCode : 543 : Diameter of Binary Tree : Brute force (Naive Solution)

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
    int height(TreeNode* root) { // function : height of tree
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right)); // max of left and right sub-tree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // base case : diameter 0 if no root exist
        if (root == NULL) return 0;
        // find all diamter and return max of them

        int diameterThroughRoot = height(root->left) + height(root->right); // diamter through root
        int diameterOfLeftSubtree = diameterOfBinaryTree(root->left); // left sub-tree
        int diameterOfRightSubtree = diameterOfBinaryTree(root->right); // right sub-tree
        // return maximum diameter
        return max(diameterThroughRoot, max(diameterOfLeftSubtree, diameterOfRightSubtree));
    }
};

int main() {
    /*
        Tree:
                1
               / \
              2   3
             / \
            4   5

        Diameter = path [4–2–5] or [4–2–1–3] → length = 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}

/*
OUTPUT:
Diameter of Tree: 3

Time Complexity: O(n^2) – for each node we compute height O(n).
Space Complexity: O(h) – recursion stack, h = height of tree (O(n) worst case).
*/