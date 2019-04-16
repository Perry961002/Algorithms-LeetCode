/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func levelOrder(root *TreeNode) [][]int {
    var result [][]int
    if root == nil {
        return result
    }
    queue := []*TreeNode{root} //队列
    for len(queue) != 0 {
        curSize := len(queue)  //当前层的结点数
        var curRow []int
        for curSize != 0 {
            curNode := queue[0] //取队头元素并弹出
            queue = queue[1:]
            if curNode.Left != nil {
                queue = append(queue, curNode.Left)
            }
            if curNode.Right != nil {
                queue = append(queue, curNode.Right)
            }
            curRow = append(curRow, curNode.Val)
            curSize--
        }
        result = append(result, curRow)
    }
    return result
}