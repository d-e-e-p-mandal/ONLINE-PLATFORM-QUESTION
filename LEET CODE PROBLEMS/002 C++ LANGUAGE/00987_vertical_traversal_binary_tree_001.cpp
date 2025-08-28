// LeetCode : 987 : Vertical Order Traversal of a Binary Tree : Optimal Solution : (row,col)

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