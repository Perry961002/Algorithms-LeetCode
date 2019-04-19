/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func flatten(root *TreeNode)  {
    head := root
    for head != nil {
        //将右子树接在head的前驱节点后面, 并交换左右子树
        if head.Left != nil {
            pre := head.Left
            //找到前驱节点
            for pre.Right != nil {
                pre = pre.Right
            }
            //拼接, 并交换
            pre.Right = head.Right
            head.Left, head.Right = nil, head.Left
        }
        head = head.Right
    }
}