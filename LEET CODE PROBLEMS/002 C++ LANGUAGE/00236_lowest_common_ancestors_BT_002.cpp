// LeetCode : 236 : Lowest Common Ancestor of a Binary Tree : (Optimal solution)

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public: // if find node return true
    bool LCA(TreeNode* root, TreeNode* node, vector<TreeNode*> &ds) {
        // base case : 
        if(root == nullptr) return false;
        if(root == node) {  // if node is find
            ds.push_back(root);
            return true;
        }

        ds.push_back(root); // store the node
        if(LCA(root -> left, node, ds)) return true;    // traverse left
        if(LCA(root -> right, node, ds)) return true;   // traverse right
        ds.pop_back(); // backtrack
        return false;  // if don't find
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // find path of p and q ans store
        vector<TreeNode*> ds1;
        vector<TreeNode*> ds2;
        // store the path
        bool x = LCA(root, p, ds1);
        bool y = LCA(root, q, ds2);

        TreeNode *ans = NULL;
        // last common element of path is ths answer
        for(int i=0; i < ds1.size() && i < ds2.size(); i++) {
            if(ds1[i]->val == ds2[i]->val) ans = ds1[i];
            else break;
        }

        return ans; // answer

    }
};

int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->left->right; // Node 2
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;

    p = root->left;      // Node 5
    q = root->right;     // Node 1
    ans = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;

    return 0;
}

/*OUTPUT :
LCA of 5 and 2 is: 5
LCA of 5 and 1 is: 3
*/

/*Time: O(n)
Space: O(h) recursion stack + O(h) path vectors = O(h) (→ O(n) worst case, O(log n) balanced tree)*/