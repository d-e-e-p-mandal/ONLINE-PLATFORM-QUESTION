// LeetCode : 199 : Binary Tree Right Side View : Level Order Traversal (using y coordinate)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        // queue for level order traversal
        queue<pair<int, TreeNode*>> q;
        // to store y cordinate and nodes value
        map<int,int> mp;

        q.push({0,root}); // push root

        while(!q.empty()) {
            TreeNode* curr = q.front().second; // current node
            int l = q.front().first; // level or y coordinate
            q.pop();

            mp[l] = curr->val; // update with last seen
            // traversal : INCREASE value of y
            if(curr->left) q.push({l+1, curr->left});   // go left
            if(curr->right) q.push({l+1, curr->right}); // go right
        }
        // store answer from map
        for(auto it : mp) {
            ans.push_back(it.second);
        }

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
SPACE COMPLEXITY: O(N)  // queue + map
*/