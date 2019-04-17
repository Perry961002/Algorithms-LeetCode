/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func reverse(nums [][]int) [][]int {
    start, end := 0, len(nums) - 1
    for start < end {
        nums[start], nums[end] = nums[end], nums[start]
        start++
        end--
    }
    return nums
}

func levelOrderBottom(root *TreeNode) [][]int {
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
    result = reverse(result)
    return result
}