import java.util.*;

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    // Store inorder traversal of BST (gives sorted order)
    public void inorder(TreeNode root, List<Integer> arr) {
        if (root == null) return;

        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }

    // Build balanced BST from sorted list
    public TreeNode bBST(List<Integer> arr, int i, int j) {
        if (i > j) return null;

        int mid = (i + j) / 2;
        TreeNode root = new TreeNode(arr.get(mid));

        root.left = bBST(arr, i, mid - 1);
        root.right = bBST(arr, mid + 1, j);

        return root;
    }

    // Main function to balance the BST
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> arr = new ArrayList<>();

        inorder(root, arr);                 // get sorted nodes
        return bBST(arr, 0, arr.size() - 1); // build balanced BST
    }
}

/* Optional main() for testing */
class Balance_a_Binary_Search_Tree_01382 {
    public static void main(String[] args) {

        /*
            Example BST (right skewed):
                1
                 \
                  2
                   \
                    3
                     \
                      4
        */

        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.right = new TreeNode(3);
        root.right.right.right = new TreeNode(4);

        Solution obj = new Solution();
        TreeNode balancedRoot = obj.balanceBST(root);

        // Inorder traversal of balanced BST
        List<Integer> res = new ArrayList<>();
        obj.inorder(balancedRoot, res);

        for (int x : res) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}

/*
-----------------------------------------
Sample Input:
BST: 1 -> 2 -> 3 -> 4 (right skewed)

Sample Output (inorder traversal):
1 2 3 4

Explanation:
The given BST is converted into a height-balanced BST
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
Extra list used to store inorder traversal
and recursion stack.

-----------------------------------------
*/