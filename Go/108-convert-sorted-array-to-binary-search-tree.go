/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func BSTBuild(nums []int, start, end int) *TreeNode {
    if start > end {
        return nil
    }
    mid := (start + end) / 2
    root := &TreeNode{
        Val: nums[mid],
        Left: nil,
        Right: nil,
    }
    root.Left = BSTBuild(nums, start, mid - 1)
    root.Right = BSTBuild(nums, mid + 1, end)
    return root
}

func sortedArrayToBST(nums []int) *TreeNode {
    return BSTBuild(nums, 0, len(nums) - 1)
}