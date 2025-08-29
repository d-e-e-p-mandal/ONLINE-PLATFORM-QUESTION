// GFG : Bottom View of Binary Tree : Optimal Solution : x coordinate 
#include <bits/stdc++.h>
using namespace std;

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Function to return a list of nodes visible from the bottom view
        // from left to right in Binary Tree.
        vector<int> ans;
        if(root == nullptr) return ans; // if no root exist
        // Storing x coordinate and Node in q
        queue<pair<int,  Node*>>q;
        // map : x (coordinate-key) and node value
        map<int,int> mp;
        
        q.push({0,root}); //// push root in queue
        
        while(!q.empty()) {
            int l = q.front().first; // level or x coordinate
            Node* curr = q.front().second; // Node
            q.pop(); //pop
            // store or update key (x-coordinate) mapped value if same key 
            mp[l] = curr->data; // last seen
             // traversal
            if(curr->left) q.push({l-1, curr->left});
            if(curr->right) q.push({l+1, curr->right});
        }
        // store answer in ans form map :
        // -x -> +x
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
                 20
               /    \
             8       22
            / \        \
           5   3        25
              / \
             10 14

        Bottom View: 5 10 3 14 25
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution sol;
    vector<int> ans = sol.bottomView(root);

    cout << "Bottom View of Binary Tree: ";
    for(int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}

/*
OUTPUT:
Bottom View of Binary Tree: 5 10 3 14 25 

TIME COMPLEXITY: O(N log N)  // N nodes, log N per map insertion
SPACE COMPLEXITY: O(N)      // queue + map storage
*/