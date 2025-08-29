// GFG : Left View of Binary Tree : Level order Traversal : (Using Coordinate : y)) 

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans; // data structure
        if(root == nullptr) return ans;
        // queue : level order traversal
        queue<pair<int, Node*>>q; 
        // map : y-level, node-value
        map<int,int> mp;
        
        q.push({0,root});
        
        while(!q.empty()) {
            Node *curr = q.front().second;
            int l = q.front().first;
            q.pop();
            
            // store first seen at each level
            if(mp.find(l)==mp.end()) {
                mp[l] = curr -> data;
            }
            // traversal
            if(curr->left) q.push({l+1, curr->left}); // go left
            if(curr->right) q.push({l+1, curr->right}); // go right
        }        
        
        // store answer in ans
        for(auto it : mp) { 
            ans.push_back(it.second);
        }

        return ans;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Constructed binary tree:
                 1
               /   \
              2     3
             / \     \
            4   5     6

        Left Side View: 1 2 4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.leftView(root);

    cout << "Left Side View of Binary Tree: ";
    for(int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}

/*
OUTPUT:
Left Side View of Binary Tree: 1 2 4

TIME COMPLEXITY: O(N)   // each node visited once
SPACE COMPLEXITY: O(N)  // queue + map
*/