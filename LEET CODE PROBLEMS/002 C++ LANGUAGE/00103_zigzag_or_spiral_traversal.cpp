// LeetCode : 103 : Binary Tree Zigzag Level Order Traversal : OR : Spiral Traversal : Optimal Solution

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
    void spiralTraversal(TreeNode* root, vector<vector<int>>& ans) {
        if(root == nullptr) return; // if empty Tree : No TreeNode exist

        queue<TreeNode*> q; // queue datastructure
        q.push(root);
        bool flag = true; // if true : traversal : left to right, if false : traversal right to left
        
        while(!q.empty()) {  // until traverse last level
            int size = q.size(); // size of queue of each level
            vector<int> row(size); // row of ans
            
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); // take each node from queue
                q.pop();
                // store val in row index
                int index = flag ? i : size - i - 1;
                row[index] = curr->val;
                // if subtree exist then push in queue
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }

            ans.push_back(row); // each row push in answer
            flag = !flag; // take opposite
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; // datastructure to store result
        spiralTraversal(root, ans); 
        return ans;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Example Tree:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7

        Zigzag traversal:
        [
          [1],
          [3,2],
          [4,5,6,7]
        ]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for(auto& row : result) {
        cout << "[ ";
        for(int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

// Output:
// Zigzag Level Order Traversal:
// [ 1 ]
// [ 3 2 ]
// [ 4 5 6 7 ]
//
// Time Complexity: O(N), Space Complexity: O(N)