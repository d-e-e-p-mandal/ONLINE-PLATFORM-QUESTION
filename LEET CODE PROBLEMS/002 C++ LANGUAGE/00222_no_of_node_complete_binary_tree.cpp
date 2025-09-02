// LeetCode : 222 : Count Complete Tree Nodes : Optimal Answer
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
    // Compute left height of tree
    int leftHeight(TreeNode* root) { 
        if(root == nullptr) return 0;   // base case
        return 1 + leftHeight(root->left);
    }

public:   
    // Compute right height of tree
    int rightHeight(TreeNode* root) {
        if(root == nullptr) return 0; // base case
        return 1 + rightHeight(root->right);
    }

public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; // base case: no node

        int leftH = leftHeight(root); 
        int rightH = rightHeight(root); 

        // If left height == right height → full binary tree
        if(leftH == rightH) return (1 << leftH) - 1;

        // Otherwise, divide and conquer
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    /*
             1
            / \
           2   3
          / \  /
         4  5 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int totalNodes = sol.countNodes(root);
    cout << "Total Nodes = " << totalNodes << endl;

    return 0;
}

/*
✅ Output:
Total Nodes = 6

💡 Explanation:
- leftHeight = 3 (nodes 1->2->4)
- rightHeight = 2 (nodes 1->3)
- Heights not equal → recursively count left and right subtree
- countNodes(root) = 1 + countNodes(left) + countNodes(right)
- Final result = 6

⏱️ Time Complexity:
- Best case (perfect binary tree): O(logN * logN)
- Worst case (skewed tree): O(N)
- Space Complexity: O(H) recursion stack, H = tree height
*/