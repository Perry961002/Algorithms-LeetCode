/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func abs(x int) int {
    if x >= 0 {
        return x
    } else {
        return -x
    }
}

func max(x, y int) int {
    if x > y {
        return x
    } else {
        return y
    }
}

func getDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    //取得左右子树的高度
    lDepth, rDepth := getDepth(root.Left), getDepth(root.Right)
    //左右子树不符合要求, 或者它们的高度差不符合要求
    if lDepth < 0 || rDepth < 0 || abs(lDepth - rDepth) > 1 {
        return -1
    }
    return max(lDepth, rDepth) + 1
}

func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }
     //取得左右子树的高度
    lDepth, rDepth := getDepth(root.Left), getDepth(root.Right)
    //左右子树不符合要求, 或者它们的高度差不符合要求
    if lDepth < 0 || rDepth < 0 || abs(lDepth - rDepth) > 1 {
        return false
    }
    return true
}