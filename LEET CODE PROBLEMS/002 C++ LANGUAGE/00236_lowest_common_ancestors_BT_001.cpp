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
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case : no node found || foundy any node
        // if(root == nullptr) return nullptr;
        // if(root == p || root == q) return root;
        //or
        if( root == nullptr || root == p || root == q) return root; 
        
        TreeNode* LCA1 = LCA(root -> left, p, q);  // left traverse
        TreeNode* LCA2 = LCA(root -> right, p, q); // right traverse
        // if left null then ans belongs to right
        // if right null then ans belongs to left
        // if both not null then both uder this node return this node
        // if both null then no answer return null
        if(LCA1 == NULL) return LCA2;
        if(LCA2 == NULL) return LCA1;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
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

/*Time Complexity: O(n) (each node visited once)
Space Complexity: O(h) (recursion stack, where h = height of tree)*/