// GFG : Burning Tree : DFS

#include <bits/stdc++.h>
using namespace std;

/*
Definition for Binary Tree Node
*/
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Utility function to calculate height of a subtree
    int height(Node* root) {
        if(root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Recursive function to calculate distance from target
    // Updates burnTime to maximum time required to burn the entire tree
    int burningTime(Node* root, int target, int* burnTime) {
        if(root == nullptr) return -1;

        // 🔥 Case 1: current node is target
        if(root->data == target) {
            *burnTime = max(height(root->left), height(root->right));
            return 0; // distance from target to itself
        }

        // 🔥 Case 2: search left subtree
        int leftBurn = burningTime(root->left, target, burnTime);
        if(leftBurn != -1) {
            int rightH = height(root->right);
            *burnTime = max(*burnTime, leftBurn + 1 + rightH);
            return leftBurn + 1; // propagate distance to parent
        }

        // 🔥 Case 3: search right subtree
        int rightBurn = burningTime(root->right, target, burnTime);
        if(rightBurn != -1) {
            int leftH = height(root->left);
            *burnTime = max(*burnTime, rightBurn + 1 + leftH);
            return rightBurn + 1;
        }

        return -1; // target not found
    }

    // Main function: returns total time to burn entire tree from target
    int minTime(Node* root, int target) {
        int burnTime = 0; // store maximum burn time
        burningTime(root, target, &burnTime); // start burning
        return burnTime;
    }
};

// Helper function to create a sample tree
Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildTree();
    Solution sol;
    int target = 2;
    int timeToBurn = sol.minTime(root, target);
    cout << "Total time to burn tree from node " << target << " is: " << timeToBurn << endl;
    return 0;
}

/*
Explanation:
Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Target = 2
Time 0: 2
Time 1: 1, 4, 5
Time 2: 3
Time 3: 6
Answer = 3

Time Complexity: O(N^2) in worst case (height calculation at each node)
Space Complexity: O(H) for recursion stack

*/