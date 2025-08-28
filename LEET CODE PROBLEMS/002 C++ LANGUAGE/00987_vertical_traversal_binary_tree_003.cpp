// LeetCode : 987 : Vertical Order Traversal of a Binary Tree : Optimal Solution : (x,y coordinate use)

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // store x coordinate and TreeNode : y coordinate will increase in each lavel
        //
        queue<pair<int, TreeNode*>> q;

        // map : acessing -x -> +x : 1st int represent x coordinate
        // using multiset to store multiple data at same ordinate
        map<int,map<int,multiset<int>>> mp;

        q.push({0,root}); // push root in the queue

        int y = 0; // level or y coordinate
        while(!q.empty()) {
            int qSize = q.size();
            // traver one level then increse y
            for(int i=0; i<qSize; i++) {
                auto [x, curr] = q.front(); // take front
        
                q.pop();                    // now pop it

                mp[x][y].insert(curr->val); // store in map
                // traverse
                if(curr->left)  q.push({x-1, curr->left});
                if(curr->right) q.push({x+1, curr->right});
            }

            y++; // increse y coordinate
        }
        // answer
        vector<vector<int>> ans;
        // store answer in ans from mp (map)
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