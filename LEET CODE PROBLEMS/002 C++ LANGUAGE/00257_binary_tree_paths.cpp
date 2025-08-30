// LeetCode : 257 : Binary Tree Paths :

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
    void paths(TreeNode* root, string s, vector<string>& ans) {
        // base case : NULL
        if(root == nullptr) return;
        // if reaches leaf node
        if(root->left == nullptr && root->right == nullptr) {
            s+= to_string(root->val); // add node data in sting format
            ans.push_back(s);   // store answer
            return;
        }
        // traversal and also add node value in string format
        paths(root->left, s + to_string(root->val) +"->", ans);
        paths(root->right, s + to_string(root->val) +"->", ans);
    }
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans; // answer

        paths(root, "", ans); // function
        return ans;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    /*
            1
           / \
          2   3
           \
            5
       Expected Paths:
       "1->2->5"
       "1->3"
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    cout << "Root-to-Leaf Paths:" << endl;
    for(string &path : result) {
        cout << path << endl;
    }

    return 0;
}

/*
Output:
Root-to-Leaf Paths:
1->2->5
1->3

Time Complexity: O(N)   // each node visited once
Space Complexity: O(H)  // recursive stack, H = height of tree
*/