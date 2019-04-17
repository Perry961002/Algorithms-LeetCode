/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    depth, q := 0, []*TreeNode{root}
    for len(q) != 0 {
        size := len(q)
        for size != 0 {
            node := q[0]
            q = q[1:]
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
            size--
        }
        depth++
    }
    return depth
}