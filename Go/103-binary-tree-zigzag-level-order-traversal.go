/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func reverse(nums []int) []int {
    start, end := 0, len(nums) - 1
    for start < end {
        nums[start], nums[end] = nums[end], nums[start]
        start++
        end--
    }
    return nums
}

func zigzagLevelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil {
        return res
    }
    queue, falg := []*TreeNode{root}, false
    for len(queue) != 0 {
        size := len(queue)
        var row []int
        for size != 0 {
            node := queue[0]
            queue, row = queue[1:], append(row, node.Val)
            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
            size--
        }
        if falg {
            row = reverse(row)
        }
        falg = !falg
        res = append(res, row)
    }
    return res
}