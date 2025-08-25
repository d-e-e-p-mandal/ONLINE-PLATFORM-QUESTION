// LeetCode : 543 : Diameter of Binary Tree : Optimal Solution

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
    int height(TreeNode* root, int* diameter) {
        // base case : height 0 if no root exist
        if(root == NULL) return 0;

        int leftHeight = height(root->left, diameter); // left-subtree
        int rightHeight = height(root->right, diameter); // right-subtree
        *diameter = max(*diameter, leftHeight + rightHeight); // updating diamter : taking max

        return 1 + max(leftHeight, rightHeight); // return height

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        //we will find diameter through height : using pointer we will take max of subtree diameter and througRoot diameter
        int diameter = 0;
        // int h = height(root, &diameter);
        height(root, &diameter);

        return diameter; // ans
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

Time Complexity: O(n) – for each node we compute height O(n).
Space Complexity: O(h) – recursion stack, h = height of tree (O(n) worst case).
*/