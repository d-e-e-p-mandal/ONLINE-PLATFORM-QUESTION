// LeetCode : 863 : All Nodes Distance K in Binary Tree : DFS : Solution

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function: collect all nodes at distance k in the subtree rooted at 'root'
    void subtreeAdd(TreeNode* root, int k, vector<int>& ans) {
        if (root == nullptr || k < 0) return;   // base case

        if (k == 0) {                           // if distance matches
            ans.push_back(root->val);
            return;
        }

        // recursive calls to left and right subtrees
        subtreeAdd(root->left, k - 1, ans);
        subtreeAdd(root->right, k - 1, ans);
    }

    // DFS to find target node and compute distances
    int distance(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if (root == nullptr) return -1; // target not found in this branch

        if (root == target) {
            // target found → collect nodes at distance k in its subtree
            subtreeAdd(root, k, ans);
            return 1; // return distance to parent
        }

        // search in left subtree
        int distL = distance(root->left, target, k, ans);
        if (distL != -1) { // target found in left subtree
            if (distL == k) ans.push_back(root->val); // ancestors : root is k distance from target
            // collect nodes in right subtree at (k - distL - 1)
            subtreeAdd(root->right, k - distL - 1, ans);
            return distL + 1; // propagate distance upwards
        }

        // search in right subtree
        int distR = distance(root->right, target, k, ans);
        if (distR != -1) { // target found in right subtree
            if (distR == k) ans.push_back(root->val); // ancestors : root is k distance from target
            // collect nodes in left subtree at (k - distR - 1)
            subtreeAdd(root->left, k - distR - 1, ans);
            return distR + 1; // propagate distance upwards
        }

        return -1; // target not found in this path
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
           // we calculate distance also : when backtrack we also add distance through ancestors
        vector<int> ans;
        distance(root, target, k, ans);
        return ans;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
         Example Tree:
                 3
                / \
               5   1
              / \ / \
             6  2 0  8
               / \
              7   4

       Target = Node(5), k = 2
       Output = [7,4,1]
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

    Solution obj;
    TreeNode* target = root->left; // Node with value 5
    int k = 2;

    vector<int> result = obj.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target(" << target->val << "): ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}

/*
------------------- OUTPUT -------------------
Nodes at distance 2 from target(5): 7 4 1

Explanation:
- Distance 2 from node 5:
    → Left Subtree: node 7 and node 4
    → Upwards to parent (3), then right child (1)

------------------- TIME COMPLEXITY -------------------
O(N), where N = number of nodes
- Each node is visited at most once in distance + subtreeAdd.

------------------- SPACE COMPLEXITY -------------------
O(H), where H = height of tree (recursion stack)
+ O(N) for storing answer
*/