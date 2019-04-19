/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func min(x, y int) int {
    if x < y {
        return x
    } else {
        return y
    }
}

func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    } else if root.Left == nil && root.Right == nil {
        return 1
    }
    lDepth, rDepth := minDepth(root.Left), minDepth(root.Right)
    if lDepth == 0 || rDepth == 0 {
        return lDepth + rDepth + 1
    }
    return min(lDepth, rDepth) + 1
}