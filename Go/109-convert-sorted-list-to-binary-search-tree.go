/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/*
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

func sortedListToBST(head *ListNode) *TreeNode {
    var nums []int
    for head != nil {
        nums = append(nums, head.Val)
        head = head.Next
    }
    return BSTBuild(nums, 0, len(nums) - 1)
}
*/

//第2种解法
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return &TreeNode{
            Val: head.Val,
            Left: nil,
            Right: nil,
        }
    }
    //快慢指针法, slow最后会是中间结点, front是它前面一个
    front, slow, fast := head, head, head
    for fast.Next != nil && fast.Next.Next != nil {
        front = slow
        slow, fast = slow.Next, fast.Next.Next
    }
    fast, front.Next = slow.Next, nil
    root := &TreeNode{
        Val: slow.Val,
        Left: nil,
        Right: nil,
    }
    if head != slow {
        root.Left = sortedListToBST(head)
    }
    root.Right = sortedListToBST(fast)
    return root
}