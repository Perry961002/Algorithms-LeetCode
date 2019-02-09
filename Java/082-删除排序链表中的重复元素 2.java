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
        ListNode p = result; // 从头结点的前一个位置开始
        while (p.next != null && p.next.next != null) {
            if (p.next.val == p.next.next.val) // 找到相同的
            {
                int target = p.next.val;
                while (p.next != null && p.next.val == target)
                    p.next = p.next.next;
            } else
                p = p.next;
        }
        return result.next;
    }
}