// LeetCode : Amount of Time for Binary Tree to Be Infected  : Buring Binary Tree : DFS Solution

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
    int maxTime = 0;  
    // Stores the maximum time needed to burn the entire tree

    // DFS function:
    // - Returns the distance of "start" node from the current root
    // - Updates maxTime whenever fire spreads to the opposite side
    int dfs(TreeNode* root, int start) {
        if(!root) return -1;  
        // base case: null node → not found, return -1

        // 🔥 Case 1: current node is the start node
        if(root->val == start) {
            // Fire starts here → maximum burning time initially is
            // the max depth of either left or right subtree
            maxTime = max(maxTime, max(height(root->left), height(root->right)));
            return 0; // distance of start from itself = 0
        }

        // 🔥 Case 2: Search in left subtree
        int leftDist = dfs(root->left, start);
        if(leftDist != -1) {  
            // Start found in left subtree
            // Fire will go up to this root (+1) and then spread down right subtree
            maxTime = max(maxTime, leftDist + 1 + height(root->right));
            return leftDist + 1; // return distance from this root to start
        }

        // 🔥 Case 3: Search in right subtree
        int rightDist = dfs(root->right, start);
        if(rightDist != -1) {
            // Start found in right subtree
            // Fire will go up to this root (+1) and then spread down left subtree
            maxTime = max(maxTime, rightDist + 1 + height(root->left));
            return rightDist + 1;
        }

        // Start not found in either subtree
        return -1;
    }

    // Utility: compute height of a subtree (max depth)
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Main function: returns the total time to burn entire tree
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start); // run DFS to calculate burning time
        return maxTime;   // return the result
    }
};

// ----------------- DRIVER CODE -----------------
int main() {
    /*
          1
         / \
        2   3
       / \   \
      4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    int start = 2;  // fire starts at node 2
    cout << sol.amountOfTime(root, start) << endl;

    return 0;
}

/*
✅ Output:
3

⏱ Time Complexity:
O(N^2) in worst case (because for every node, `height()` may traverse subtree).  
Can be optimized to O(N) with memoization or single DFS.

💾 Space Complexity:
O(H), where H = height of tree (stack recursion).

📘 Explanation:
Fire starts at node 2 → burns nodes 4 & 5 → then root (1) → then node 3 → finally node 6.  
Total time taken = 3.
*/