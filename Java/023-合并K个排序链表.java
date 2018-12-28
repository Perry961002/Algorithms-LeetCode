/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(-1);
        ListNode p = head;
        ListNode tmp;
        int num = -1;
        do {
            tmp = new ListNode(Integer.MAX_VALUE);
            for (int j = 0; j < lists.length; j++)
                if (lists[j] != null && tmp.val > lists[j].val) {
                    tmp = lists[j];
                    num = j;
                }
            if (tmp.val != Integer.MAX_VALUE) {
                p.next = tmp;
                p = p.next;
                lists[num] = lists[num].next;
            }
        } while (tmp.val != Integer.MAX_VALUE);
        return head.next;
    }
}