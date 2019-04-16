/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 var (
    first *TreeNode
    second *TreeNode
    pre *TreeNode
)

//中序遍历二叉树，找到递减的节点，如果有一个交换他们相邻的，如果有两个，交换这两个
func inorder(root *TreeNode) {
    if root == nil {
        return
    }
    if root.Left != nil {
        inorder(root.Left)
    }
    if pre != nil && pre.Val > root.Val {
        if first == nil {
            first = pre
        }
        second = root
    }
    pre = root
    if root.Right != nil {
        inorder(root.Right)
    }
}

func recoverTree(root *TreeNode)  {
    first, second, pre = nil, nil, nil
    if root == nil {
        return
    }
    inorder(root)
    first.Val, second.Val = second.Val, first.Val
}