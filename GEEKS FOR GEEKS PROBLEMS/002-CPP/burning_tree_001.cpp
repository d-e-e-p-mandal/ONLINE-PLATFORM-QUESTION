// GFG : Burning Tree : BFS
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Step 1: Build a parent map for each node and find the target node
    Node* parentMap(Node* root, int target, unordered_map<Node*, Node*>& parent_track) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // Map children to their parent
            if(curr->left) parent_track[curr->left] = curr;
            if(curr->right) parent_track[curr->right] = curr;
            
            // If current node is the target, return it
            if(curr->data == target) return curr;
            
            // Continue BFS traversal
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
        return NULL; // target not found (should not happen if target exists)
    }
    
public:
    // Step 2: Calculate minimum time to burn entire tree from target
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track; // child → parent mapping
        Node *start = parentMap(root, target, parent_track); // find target node
        
        unordered_map<Node*, bool> burned; // track burned nodes
        queue<Node*> q;
        q.push(start);      // start BFS from the target node
        burned[start] = true;
        
        int burnTime = -1; // initialize time (-1 because first increment happens at start)
        
        while(!q.empty()) {
            int qSize = q.size(); // number of nodes burning at this time unit
            burnTime++;           // each BFS level = 1 unit of time
            
            // Process all nodes burning at this time
            for(int i = 0; i < qSize; i++) {
                Node *curr = q.front();
                q.pop();
                
                // Burn left child if not already burned
                if(curr->left && !burned[curr->left]) {
                    burned[curr->left] = true;
                    q.push(curr->left);
                }
                
                // Burn right child if not already burned
                if(curr->right && !burned[curr->right]) {
                    burned[curr->right] = true;
                    q.push(curr->right);
                }
                
                // Burn parent if not already burned
                if(parent_track[curr] && !burned[parent_track[curr]]) {
                    burned[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
        }
        
        return burnTime; // total time to burn the entire tree
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    Solution sol;
    int target = 2;
    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the tree starting from node " << target << " = " << result << endl;
    
    return 0;
}

/*
✅ Output:
Minimum time to burn the tree starting from node 2 = 3

💡 Explanation:
- Fire starts at node 2
- Step 1: burn 4,5,1 (neighbors of 2)
- Step 2: burn 3 (neighbor of 1)
- Step 3: burn 6 (neighbor of 3)
- Total steps = 4

⏱️ Time Complexity:
- O(N), we visit each node once
- Space Complexity: O(N) for queue and parent map
*/