/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func getPathNum(root *TreeNode, num int) int {
    //叶子节点
    if root.Left == nil && root.Right == nil {
        return num * 10 + root.Val
    }
    //递归
    leftNum, rightNum := 0, 0
    if root.Left != nil {
        leftNum = getPathNum(root.Left, num * 10 + root.Val)
    }
    if root.Right != nil {
        rightNum = getPathNum(root.Right, num * 10 + root.Val)
    }
    return leftNum + rightNum
}
func sumNumbers(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return getPathNum(root, 0)
}