// LeetCode : 104 : Tree : Maximum Depth of Binary Tree : Recursive

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; // if no node
        // height : current Node height (1) + maximum all posibility
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Helper: create sample tree
TreeNode* createSampleTree() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    Solution sol;
    cout << "Maximum depth of tree: " << sol.maxDepth(root) << endl;

    return 0;
}

/* Maximum depth of tree: 3 */

/*Time Complexity: O(n),
Space Complexity: O(h) where n = number of nodes, h = height of tree (due to stack).*/