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
    // Utility function to compute the height of a binary tree.
    // Height = number of nodes on the longest path from this node to a leaf.
    int height(TreeNode* root) {
        if(root == nullptr) return 0;   // base case: null tree has height 0

        // height = 1 (for current node) + max height of left/right subtree
        return 1 + max(height(root->left), height(root->right));
    }

public:
    // Recursive function to calculate burning time from the start node.
    // Parameters:
    //  - root: current node being checked
    //  - start: the value where fire starts
    //  - maxCost: pointer storing the maximum time taken so far
    //
    // Returns:
    //  - distance of "start" node from the current root
    //  - OR -1 if start is not found in this subtree
    int burningTime(TreeNode* root, int start, int* maxCost) {
        if(root == nullptr) return -1;   // base case: start not found here

        // 🔥 Case 1: Found the start node
        if(root->val == start) {
            // When fire starts at this node, the farthest it can spread
            // is the maximum height of its left/right subtree.
            *maxCost = max(height(root->left), height(root->right));
            return 0; // distance from itself = 0
        }

        // 🔥 Case 2: Search in left subtree
        int leftBurn = burningTime(root->left, start, maxCost);
        if(leftBurn != -1) {  
            // start node found in left subtree
            // Fire will travel through root and spread into right subtree
            int rightB = 1 + height(root->right);  // 1 step (to root) + height of right
            *maxCost = max(*maxCost, leftBurn + rightB);
            return leftBurn + 1;  // distance from root to start = leftBurn+1
        }

        // 🔥 Case 3: Search in right subtree
        int rightBurn = burningTime(root->right, start, maxCost);
        if(rightBurn != -1) {  
            // start node found in right subtree
            // Fire will travel through root and spread into left subtree
            int leftB = 1 + height(root->left);
            *maxCost = max(*maxCost, rightBurn + leftB);
            return rightBurn + 1; // distance from root to start
        }

        // start not found in this subtree
        return -1;
    }

public:
    // Main function: returns the total time required to burn the entire tree
    int amountOfTime(TreeNode* root, int start) {
        int maxCost = 0; // track maximum burning time

        // Begin recursive search for burning time
        burningTime(root, start, &maxCost);

        return maxCost;  // result: time to burn the entire tree
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