import java.util.*;

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null)
            return head;
        ListNode mylist = new ListNode(0); // 构造头结点
        mylist.next = head;
        ListNode p = mylist;
        ListNode q = mylist;
        for (int i = 0; i < n; i++)
            q = q.next;
        while (q.next != null) {
            q = q.next;
            p = p.next;
        }
        q = p.next;
        p.next = p.next.next;
        return mylist.next;
    }
}