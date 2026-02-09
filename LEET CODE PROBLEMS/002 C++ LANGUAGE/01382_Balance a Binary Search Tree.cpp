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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Store inorder traversal of BST (gives sorted order)
    void inOrder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

    // Build balanced BST from sorted array
    TreeNode* bBST(vector<int>& arr, int i, int j) {
        if (i > j) return nullptr;

        int m = (i + j) / 2;
        TreeNode* root = new TreeNode(arr[m]);

        root->left = bBST(arr, i, m - 1);
        root->right = bBST(arr, m + 1, j);

        return root;
    }

    // Main function to balance BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inOrder(root, arr);                 // get sorted nodes
        return bBST(arr, 0, arr.size() - 1); // build balanced BST
    }
};

/* Optional main() for testing */
int main() {
    /*
        Example BST (skewed):
            1
             \
              2
               \
                3
                 \
                  4
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution obj;
    TreeNode* balancedRoot = obj.balanceBST(root);

    // Inorder traversal of balanced BST
    vector<int> res;
    obj.inOrder(balancedRoot, res);

    for (int x : res)
        cout << x << " ";

    cout << endl;
    return 0;
}

/*
-----------------------------------------
Sample Input:
BST: 1 -> 2 -> 3 -> 4 (right skewed)

Sample Output (inorder of balanced BST):
1 2 3 4

Explanation:
The BST is converted into a height-balanced BST
using inorder traversal and divide-and-conquer.

-----------------------------------------
Time Complexity:
O(n)
Reason:
Inorder traversal takes O(n),
building balanced BST also takes O(n).

-----------------------------------------
Space Complexity:
O(n)
Reason:
Extra array used to store inorder traversal
and recursion stack.

-----------------------------------------
*/