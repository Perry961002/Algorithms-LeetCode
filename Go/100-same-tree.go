/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isSameTree(p *TreeNode, q *TreeNode) bool {
    //p, q都是nil
    if p == nil && q == nil {
        return true
    } else if p == nil || q == nil {
        //只有一个为空
        return false
    } else {
        return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
    }
}