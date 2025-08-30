// LeetCode : 863 : All Nodes Distance K in Binary Tree : BFS : Solution

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
    void parentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        // node mapped parrent :
        queue<TreeNode*> q; // level order traversal
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front(); // current
            q.pop();
            // if left exist
            if(curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            // if right exist
            if(curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we store also parent of each node so that we can traverse upword
        unordered_map<TreeNode*, TreeNode*> parent_track;
        parentMap(root, parent_track); // function to store parent
        
        queue<TreeNode*> q; // level order traversal
        // we will find k-th disatance form target : 1.left 2.right 3.upword(parent)

        unordered_map<TreeNode*, bool> visited; // store only once so we use visited map

        q.push(target); 
        visited[target] = true;
        // we will travel k-1 distance form target, k th distance node left in the q (queue) (that is answer)
        int distance = 0; 
        // level order traversal
        while(!q.empty()) {
            int qSize = q.size();
            if(distance++ == k) break;

            for(int i=0; i<qSize; i++) {
                TreeNode *curr = q.front(); // current
                q.pop();
                // left 
                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // right
                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // parent
                if(parent_track[curr] && !visited[parent_track[curr]]) {
                    visited[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
        }

        vector<int> ans; // datastructure
        // node value store in ans
        while(!q.empty()) { 
            int it = q.front()->val;
            ans.push_back(it);
            q.pop();
        }

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
O(N), N = number of nodes
- BFS visits each node once + parent map construction.

------------------- SPACE COMPLEXITY -------------------
O(N), for parent map + queue + visited map.
*/