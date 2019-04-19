/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }
    //只有根节点且满足和
    if root.Left == nil && root.Right == nil && root.Val == sum {
        return true
    }
    target := sum - root.Val
    //递归
    if hasPathSum(root.Left, target) {
        return true
    }
    if hasPathSum(root.Right, target) {
        return true
    }
    return false
}