// GFG : Left View of Binary Tree : Optimal Solution

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
    // We will choose dfs over bfs because:
    // bfs takes O(N) space (2^level in complete tree)
    // dfs takes O(H) space (height), so optimal
    void leftSideView(Node* root, vector<int>& ans, int level) {
        if(root == nullptr) return;
        
        // sotore node value if it 1st time in level
        if(ans.size() == level) ans.push_back(root->data);
        
        // traversal
        leftSideView(root->left, ans, level+1); // go left
        leftSideView(root->right, ans, level+1); // go right
    }
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans; // data structure
        
        leftSideView(root, ans, 0);
        
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
SPACE COMPLEXITY: O(H)  // recursion stack (H = tree height)
*/