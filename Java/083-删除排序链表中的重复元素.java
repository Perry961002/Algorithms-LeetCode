/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // 因为已经排序了，只需考虑当前节点和以一个节点的val是否相等即可，相等了就删除
        if (head == null || head == null)
            return head;
        ListNode result = new ListNode(0); // 保存头结点
        result.next = head;
        ListNode p = result.next;
        while (p.next != null) {
            if (p.val == p.next.val) // 找到相同的
            {
                int target = p.val;
                while (p.next != null && p.next.val == target)
                    p.next = p.next.next;
            } else
                p = p.next;
        }
        return result.next;
    }
}