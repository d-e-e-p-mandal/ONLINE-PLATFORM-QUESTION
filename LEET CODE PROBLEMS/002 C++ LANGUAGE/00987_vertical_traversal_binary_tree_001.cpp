// LeetCode : 987 : Vertical Order Traversal of a Binary Tree : Optimal Solution : (row,col) graph based

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // queue is used to store level order triversal :
        // we store the (r,w) coordinate and TreeNode // row and column : graph based
        queue<pair<pair<int,int>, TreeNode*>> q;

        // map : acessing -c -> +c : 1st int represent column
        // using multiset to store multiple data at same ordinate
        map<int, map<int, multiset<int>>> mp;
        
        q.push({{0,0}, root}); // push root in the queue

        while(!q.empty()) {
            TreeNode* curr = q.front().second;

            int r = q.front().first.first;
            int c = q.front().first.second;
            //auto [x, y] = q.front().first; // same as previous 2 line

            q.pop();

            // push the node data in map 
            // we take element left to right : so we maped column first : col : left -> right
            mp[c][r].insert(curr -> val);
            // triverse
            if(curr->left) q.push({{r+1, c-1}, curr->left});
            if(curr->right) q.push({{r+1, c+1}, curr->right});
        }
        // vector to store answer
        vector<vector<int>> ans;
        // store answer in ans form mp (map)
        for(auto it : mp) {
            vector<int> colAns; 
            for(auto col : it.second) {
                colAns.insert(colAns.end(),col.second.begin(), col.second.end()); // push complete row form multiset
            }
            ans.push_back(colAns);
        }

        return ans; // answer
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Constructed binary tree:
                 3
               /   \
              9     20
                   /  \
                  15   7

        Vertical Order:
        [
          [9],
          [3, 15],
          [20],
          [7]
        ]
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.verticalTraversal(root);

    cout << "Vertical Traversal Output:\n";
    for(auto &col : ans) {
        cout << "[ ";
        for(int val : col) cout << val << " ";
        cout << "]\n";
    }

    return 0;
}

/*
OUTPUT:
Vertical Traversal Output:
[ 9 ]
[ 3 15 ]
[ 20 ]
[ 7 ]

TIME COMPLEXITY:
- BFS traversal: O(N)
- Insertion in multiset (log k per insertion, k ≤ N): O(N log N)
- Map traversal to build answer: O(N)
=> Overall: O(N log N)

SPACE COMPLEXITY:
- Queue + map + multiset storage: O(N)
*/