/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null)
            return head;
        ListNode end = head; // 增加尾指针
        int len = 1; // 链表的长度
        while (end.next != null) // 找到尾节点
        {
            len++; // 长度加1
            end = end.next;
        }
        int move = k % len; // k很大时会有周期，取余减少操作
        if (move == 0) // 正好和原链表一致
            return head;
        move = len - move; // 真正的移动数
        end.next = head; // 形成循环链表
        while (move-- != 0) // 旋转，移动两个节点
        {
            end = end.next;
            head = head.next;
        }
        end.next = null; // 取消尾指针
        return head;
    }
}