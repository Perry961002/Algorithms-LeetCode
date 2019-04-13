/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    result := &ListNode {-1, nil} //最后的和链表
    res := result
    sum := 0 //每位上数字的和
    for l1 != nil || l2 != nil {
        //求每位的和
        if(l1 != nil) {
            sum += l1.Val
            l1 = l1.Next
        }
        if(l2 != nil) {
            sum += l2.Val
            l2 = l2.Next
        }
        //产生链表结点, 并处理进位
        res.Next = &ListNode {sum % 10, nil}
        sum /= 10
        res = res.Next
    }
    if sum != 0 {
        res.Next = &ListNode {sum, nil}
    }
    return result.Next
}