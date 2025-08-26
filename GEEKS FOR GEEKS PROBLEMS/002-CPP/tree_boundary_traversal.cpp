// GFG : Tree Boundary Traversal : Binary Tree : Optimal Solution
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    bool isLeaf(Node* root) {  // Node is leaf or not check function
        return ( root && (root ->left == NULL) && (root -> right == NULL));
    }
  public:
    void addLeftBoundary(Node *root, vector<int>& ans) { // adding all left boundary
        Node* curr = root -> left; // taking left of root 
        
        while(curr) {
            if(!isLeaf(curr))
                ans.push_back(curr->data);
            // if left exist go to left 
            // if left does not exist go to right
            // if both does not exist : assign null : else case : it automatically assign null
            if(curr->left) curr = curr -> left;
            else curr = curr -> right;
        }
    }
  public:
    void addLeavesBoundary(Node *root, vector<int>& ans) {
        // base case : if root is null and if leaf add in answer and return
        if(root == NULL) return;
        if(isLeaf(root)) {
            ans.push_back(root -> data);
            return;
        }
        addLeavesBoundary(root->left, ans);
        addLeavesBoundary(root->right, ans);
    }
  public:
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node *curr = root -> right; // taking right of root
        // Anti clock : we will add right bottom to top : so store in temporary
        vector<int> temp; 
        while(curr) {
            if(!isLeaf(curr))
            temp.push_back(curr->data);
            // if right exist go to right
            // if right does not exist go to left
            // if both does not exist : assign null : else case : it automatically assign null

            if(curr->right) curr = curr -> right;
            else curr = curr -> left;
        }
        // taking reverse order
        for(int i = temp.size()-1; i>=0; i--) {
            ans.push_back(temp[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // boundary Traversal : Anti Clock-Wise
        
        vector<int> ans; // datastructure
        if(root == NULL) return ans;
        
        // any Node may be leaf node : but we only assign once 
        
        // anti clock : order : top->left->leaves->right
        // add : top of tree : means add root only 
        if(!isLeaf(root))ans.push_back(root->data);
        // add : left
        addLeftBoundary(root, ans);
        // add : buttom
        addLeavesBoundary(root, ans);
        // add : right
        addRightBoundary(root, ans);
        
        return ans;
        
    }
};

// ------------------ MAIN FUNCTION ------------------
int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \    \
            4   5    6
               / \
              7   8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> res = obj.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for(int val : res) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Expected Output:
Boundary Traversal: 1 2 4 7 8 6 3 

Time Complexity: O(N)   // visiting each node once
Space Complexity: O(H)  // recursion + extra vectors (H = height of tree, O(N) worst case)
*/