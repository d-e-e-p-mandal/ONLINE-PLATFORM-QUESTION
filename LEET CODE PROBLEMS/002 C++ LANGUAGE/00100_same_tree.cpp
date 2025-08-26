// LeetCode : 100 : Same Tree : Optimal Solution
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case : if both TreeNode ended
        if(p == nullptr && q == nullptr) return true;
        // false : if one of them ended
        if(p == nullptr) return false;
        if(q == nullptr) return false;
        // check val of and left and right node of root
        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Example trees:
            Tree 1:       1
                         / \
                        2   3
            Tree 2:       1
                         / \
                        2   3
        Expected: true
    */

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSameTree(tree1, tree2);
    cout << "Are the two trees identical? " << (result ? "Yes" : "No") << endl;

   
    return 0;
}

// Output: Are the two trees identical? Yes
// Time Complexity: O(N), Space Complexity: O(H) where H = height of tree (recursion stack)
