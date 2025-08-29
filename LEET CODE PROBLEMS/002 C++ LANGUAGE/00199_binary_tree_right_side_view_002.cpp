// LeetCode : 199 : Binary Tree Right Side View : Optimal Solution

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
    // We will choose dfs over bfs because:
    // bfs takes O(N) space (2^level in complete tree)
    // dfs takes O(H) space (height), so optimal

    void rightView(TreeNode* root, vector<int>& ans, int level) {
        if(root == nullptr) return; // null pointer

        // store node value if it’s first time in this level
        if(ans.size() == level) {   
            ans.push_back(root -> val);
        }
        // traversal
        rightView(root->right, ans, level+1); // go right
        rightView(root->left, ans, level+1);  // go left
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // datastructure
        rightView(root, ans, 0); // function call
        return ans; // answer
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Constructed binary tree:
                 1
               /   \
              2     3
               \     \
                5     4

        Right Side View: 1 3 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> ans = sol.rightSideView(root);

    cout << "Right Side View of Binary Tree: ";
    for(int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}

/*
OUTPUT:
Right Side View of Binary Tree: 1 3 4 

TIME COMPLEXITY: O(N)   // each node visited once
SPACE COMPLEXITY: O(H)  // recursion stack (H = tree height)
*/