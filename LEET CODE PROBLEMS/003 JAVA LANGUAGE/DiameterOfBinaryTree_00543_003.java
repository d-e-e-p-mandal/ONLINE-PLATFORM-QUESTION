// LeetCode : 543 : Diameter of Binary Tree : Optimal Solution

/**
 * Definition for a binary tree node.
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int height(TreeNode root, int [] diameter) {
        // base case : if no root exist then height of tree is 0
        if(root == null) return 0;
        // find left and right both height and update diameter of left and right subtree
        int leftHeight = height(root.left, diameter);
        int rightHeight = height(root.right, diameter); 
        
        diameter[0] = Math.max(diameter[0], leftHeight + rightHeight); // taking max diameter

        return 1 + Math.max(leftHeight, rightHeight); // return height
    }

    public int diameterOfBinaryTree(TreeNode root) {
        // no pointer exist in java : for reference taking it as array
        int[] diameter = new int[1]; // only one element
        height(root, diameter);
        return diameter[0]; // ans
    }
}

public class DiameterOfBinaryTree_00543_003 {
    public static void main(String[] args) {
        /*
            Tree:
                    1
                   / \
                  2   3
                 / \
                4   5

            Diameter = path [4–2–5] or [4–2–1–3] → length = 3
        */

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        Solution sol = new Solution();
        System.out.println("Diameter of Tree: " + sol.diameterOfBinaryTree(root));
    }
}

/*
OUTPUT:
Diameter of Tree: 3

Time Complexity: O(n) – each node visited once.
Space Complexity: O(h) – recursion stack, h = height of tree.
*/
