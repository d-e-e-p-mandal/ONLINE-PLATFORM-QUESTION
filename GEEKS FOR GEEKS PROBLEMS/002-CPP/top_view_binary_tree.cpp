// GFG : Top View of Binary Tree : Optimal Solution : x - ordinate view

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == nullptr) return ans; // if no root exist
        // Storing x coordinate and Node in q
        queue<pair<int, Node*>>q;
        // map : x (coordinate-key) and node value 
        map<int,int> mp;
        
        q.push({0,root}); // push root in queue
        // level order traversal
        while(!q.empty()) {
            int l = q.front().first;  // level or x coordinate
            Node* curr = q.front().second; // node
            q.pop();
            // store if key (x-coordinate) is 1st time
            if(mp.find(l) == mp.end()) {    // 1st seen
                mp[l] = curr->data;
            }
            // traversal
            if(curr->left) q.push({l-1, curr->left});
            if(curr->right) q.push({l+1, curr->right});
        }
        // store answer in ans form map 
        // -x -> +x
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        // answer
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
               \   / \
                4 5   6
                 \
                  7

        Top View: 2 1 3 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    Solution sol;
    vector<int> ans = sol.topView(root);

    cout << "Top View of Binary Tree: ";
    for(int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}

/*
OUTPUT:
Top View of Binary Tree: 2 1 3 6 

TIME COMPLEXITY: O(N log N)  // N nodes, log N per map insertion
SPACE COMPLEXITY: O(N)      // queue + map storage
*/