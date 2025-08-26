// LeetCode : 662 : Maximum Width of Binary Tree : Optimal Solution
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
    int widthOfBinaryTree(TreeNode* root) {
        // we initilize tree in array : root at 0 index and root at 1 index : we use at 0 index for this question
        // queue : we store pair value : Node and its position in array
        // queue
        // constraints : range 3000 : if it only left - left or right right (2*i + 1/2) exceed the range of int
        queue<pair<TreeNode*, unsigned long long>> q; 
        q.push({root, 0}); // push root
        int maxWidth = 0;  
        // untill q is not empty explore all level
        while(!q.empty()) {
            int firstIndex = (int) q.front().second;  // position of 1st Node of queue in array
            int lastIndex = (int) q.back().second;    // position of last Node of queue in array
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1); // taking max width

            int qSize = q.size(); // size of queue
            // push all Node of next level and pop current level
            for(int i=0; i<qSize; i++) {
                TreeNode* curr = q.front().first;
                int posInd = (int) q.front().second; // current position
                if(curr -> left) {  // push if left node exist
                    q.push({curr -> left, (unsigned long long) 2 * posInd + 1}); // typecasting
                }
                if(curr -> right) { // push if right node exist
                    q.push({curr->right, (unsigned long long) 2 * posInd + 2}); // typecasting
                }

                q.pop();
            }
        }

        return maxWidth; // ans
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Example tree:
                 1
               /   \
              3     2
             / \     \
            5   3     9
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << "Maximum Width of Binary Tree = " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}

// Output: Maximum Width of Binary Tree = 4
// Time Complexity: O(N), Space Complexity: O(N)