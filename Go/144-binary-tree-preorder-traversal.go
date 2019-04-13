/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return make([]int, 0)
    }
    stack := []*TreeNode{root}
    var res []int
    for len(stack) != 0 {
        cur := stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        res = append(res, cur.Val)
        if cur.Right != nil {
            stack = append(stack, cur.Right)
        }
        if cur.Left != nil {
            stack = append(stack, cur.Left)
        }
    }
    return res
}