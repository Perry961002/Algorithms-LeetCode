/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func reverse(nums []int) []int{
    i, j := 0, len(nums) - 1
    for i < j {
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1
    }
    return nums
}

func postorderTraversal(root *TreeNode) []int {
    if root == nil {
        return make([]int, 0)
    }
    stack := []*TreeNode{root}
    var res []int
    for len(stack) != 0 {
        cur := stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        res = append(res, cur.Val)
        if cur.Left != nil {
            stack = append(stack, cur.Left)
        }
        if cur.Right != nil {
            stack = append(stack, cur.Right)
        }
    }
    return reverse(res)
}