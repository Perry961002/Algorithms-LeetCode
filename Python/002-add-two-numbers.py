# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        tmp = result
        #每一位相加的和
        sum = 0
        while l1 != None or l2 != None:
            if l1 != None:
                sum += l1.val
                l1 = l1.next
            if l2 != None:
                sum += l2.val
                l2 = l2.next
            #计算当前结果，以及产生的进位
            tmp.next = ListNode(sum % 10)
            sum //= 10
            tmp = tmp.next
        #处理最后的进位
        if sum:
            tmp.next = ListNode(sum)
        return result.next