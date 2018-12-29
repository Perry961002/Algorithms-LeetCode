/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null) return head;
        ListNode p = head;
        while(p != null && p.next != null)
        {   //交换节点的值即可，不用交换节点
            int temp = p.val;
            p.val = p.next.val;
            p.next.val = temp;
            p = p.next.next;
        }
        return head;
    }
}