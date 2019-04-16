/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//检查两个树是不是对称
func isSymmetricTowTree(p, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    } else if p == nil || q == nil{
        return false
    } else {
        if p.Val != q.Val {
            return false
        }
        return isSymmetricTowTree(p.Left, q.Right) && isSymmetricTowTree(p.Right, q.Left)
    }
}


func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return isSymmetricTowTree(root.Left, root.Right)
}