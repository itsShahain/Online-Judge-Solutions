/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 class Pair {
    double l, r;

    Pair(double l, double r) {
        this.l = l;
        this.r = r;
    }
}

class Solution {
     private Pair solve(TreeNode node) {
        if (node == null) {
            return new Pair(Double.NEGATIVE_INFINITY, Double.NEGATIVE_INFINITY);
        } else {
            Pair wish1 = solve(node.left);
            Pair wish2 = solve(node.right);
            double best =
                    Math.max(wish1.l,
                            Math.max(wish2.l,
                                    Math.max(node.val,
                                            Math.max(node.val + wish1.r,
                                                    Math.max(node.val + wish2.r,
                                                            node.val + wish1.r + wish2.r)))));
            double currBestChainSum =
                    Math.max(node.val,
                            Math.max(node.val + wish1.r,
                                    node.val + wish2.r));
            return new Pair(best, currBestChainSum);
        }
    }

    public int maxPathSum(TreeNode root) {
        return (int) solve(root).l;
    }
}
