// GFG : Root to Leaf Paths
#include <bits/stdc++.h>
using namespace std;

/*
Definition for Binary Tree Node
*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void leafPaths(Node* root,vector<int>& col, vector<vector<int>>& ans) {
        // base case :
        if(root == nullptr) return; // NULL
        // leaf Node :
        if(root->left == NULL && root->right==NULL){
            col.push_back(root->data);
            ans.push_back(col);
            col.pop_back();
            return;
        }
        
        // traversal :
        col.push_back(root->data); // store Node data
        leafPaths(root->left, col, ans);
        leafPaths(root->right, col, ans);
        // backtrack
        col.pop_back();
        
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // datastructure
        vector<vector<int>> ans; 
        vector<int> col;
        
        leafPaths(root, col, ans);
        
        return ans;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    // Construct Binary Tree:
    //          10
    //        /    \
    //      20      30
    //     /  \       \
    //    40  50       60
    //                  /
    //                70
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->right->right->left = new Node(70);

    Solution obj;
    vector<vector<int>> result = obj.Paths(root);

    cout << "Root to Leaf Paths:" << endl;
    for(auto& path : result) {
        for(int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
------------------- OUTPUT -------------------
Root to Leaf Paths:
10 20 40
10 20 50
10 30 60 70

Explanation:
- Path 1: 10 → 20 → 40
- Path 2: 10 → 20 → 50
- Path 3: 10 → 30 → 60 → 70

------------------- TIME COMPLEXITY -------------------
O(N), where N = number of nodes
Reason: Each node is visited once.

------------------- SPACE COMPLEXITY -------------------
O(H), where H = height of tree
Reason: Recursion stack + temporary path vector.
*/