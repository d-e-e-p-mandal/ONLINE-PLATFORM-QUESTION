import java.util.*;

// TreeNode definition
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

// Tuple class (unchanged)
class Tuple {
    TreeNode node;
    int row;
    int col;
    public Tuple(TreeNode _node, int _row, int _col) {
        node = _node;
        row = _row;
        col = _col;
    }
}

// Solution class (unchanged)
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Tuple> q = new LinkedList<Tuple>();
        q.offer(new Tuple(root, 0, 0));
        while(!q.isEmpty()) {
            Tuple tuple = q.poll();
            TreeNode node = tuple.node;
            int x = tuple.row;
            int y = tuple.col;
            
            if (!map.containsKey(x)) {
                map.put(x, new TreeMap<>());
            }
            if (!map.get(x).containsKey(y)) {
                map.get(x).put(y, new PriorityQueue<>());
            }
            map.get(x).get(y).offer(node.val);
            
            if(node.left != null) {
                q.offer(new Tuple(node.left, x - 1, y + 1));
            }
            if(node.right != null) {
                q.offer(new Tuple(node.right, x + 1, y + 1));
            }
        }
        
        List<List<Integer>> list = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> ys : map.values()) {
            list.add(new ArrayList<>());
            for (PriorityQueue<Integer> nodes : ys.values()) {
                while (!nodes.isEmpty()) {
                    list.get(list.size() - 1).add(nodes.poll());
                }
            }
        }
        return list;
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        /*
               3
              / \
             9   20
                /  \
               15   7

          Vertical Traversal: [[9],[3,15],[20],[7]]
        */

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        Solution sol = new Solution();
        List<List<Integer>> result = sol.verticalTraversal(root);

        System.out.println("Vertical Traversal of Binary Tree:");
        for(List<Integer> col : result) {
            System.out.println(col);
        }
    }
}

/*
OUTPUT:
Vertical Traversal of Binary Tree:
[9]
[3, 15]
[20]
[7]

TIME COMPLEXITY: O(N logN)   // TreeMap + PriorityQueue operations
SPACE COMPLEXITY: O(N)       // Queue + Map + Result
*/