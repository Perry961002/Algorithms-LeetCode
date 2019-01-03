# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None:
            return None
        result = ListNode(-1)
        result.next = head
        p = result
        q = result
        for i in range(n):
            q = q.next
        while q.next:
            p = p.next
            q = q.next
        p.next = p.next.next
        return result.next