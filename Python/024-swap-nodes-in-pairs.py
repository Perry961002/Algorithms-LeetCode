# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        result = ListNode(-1)
        result.next = head
        cur = result
        while cur.next and cur.next.next:
            first = cur.next
            second = first.next
            rest = second.next
            #改变first和second的顺序
            first.next = rest
            second.next = first
            #让cur的next指针指向second
            cur.next = second
            #处理下两对节点
            cur = first
        return result.next