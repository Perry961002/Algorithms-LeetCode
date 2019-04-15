/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func inorderTraversal(root *TreeNode) []int {
    var stack []*TreeNode
    var res []int
    for root != nil || len(stack) != 0 {
        if root != nil {
            stack, root = append(stack, root), root.Left
        } else {
            root, stack = stack[len(stack)- 1], stack[:len(stack) - 1]
            res, root = append(res, root.Val), root.Right
        }
    }
    return res
}

func isValidBST(root *TreeNode) bool {
    list := inorderTraversal(root)
    for i := 1; i < len(list); i++ {
        if list[i] <= list[i - 1] {
            return false
        }
    }
    return true
}