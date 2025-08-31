// LeetCode : Amount of Time for Binary Tree to Be Infected  : Buring Binary Tree : BFS Solution

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
    // Builds the parent map while searching for the target start node.
    TreeNode* parentMap(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent_track, int start) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val == start) return curr; // found start node

            // mapping parents
            if(curr->left) parent_track[curr->left] = curr;
            if(curr->right) parent_track[curr->right] = curr;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return NULL;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* target = parentMap(root, parent_track, start);

        queue<TreeNode*> q;
        map<TreeNode*, bool> burned;

        q.push(target);
        burned[target] = true; // fire starts here
        int burnTime = -1;

        // BFS to spread fire
        while(!q.empty()) {
            int qSize = q.size();
            burnTime++;

            for(int i=0; i<qSize; i++) {
                TreeNode *curr = q.front();
                q.pop();

                // spread to left
                if(curr->left && !burned[curr->left]) {
                    q.push(curr->left);
                    burned[curr->left] = true;
                }
                // spread to right
                if(curr->right && !burned[curr->right]) {
                    q.push(curr->right);
                    burned[curr->right] = true;
                }
                // spread upward
                if(parent_track[curr] && !burned[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    burned[parent_track[curr]] = true;
                }
            }
        }
        return burnTime;
    }
};

int main() {
    /*
             1
            / \
           2   3
          /   / \
         4   5   6
    Fire starts at node = 5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    int start = 5;
    cout << "Burning Time = " << sol.amountOfTime(root, start) << endl;

    return 0;
}

/*
🔎 DRY RUN:
Start = 5
Step 0: burn {5}
Step 1: burn {3}
Step 2: burn {1, 6}
Step 3: burn {2}
Step 4: burn {4}
=> Total time = 4

✅ OUTPUT:
Burning Time = 4

⏱️ TIME COMPLEXITY:
- Building parent map: O(N) (BFS traversal)
- Burning simulation: O(N) (each node visited once)
Overall: O(N)

📦 SPACE COMPLEXITY:
- Parent map: O(N)
- Burned map + queue: O(N)
Overall: O(N)
*/