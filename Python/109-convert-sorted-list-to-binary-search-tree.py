# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if head == None:
            return None
        elif head.next == None:
            return TreeNode(head.val)
        #快慢指针法, slow最后会是中间结点, front是它前面一个
        front, slow, fast = head, head, head
        while fast.next and fast.next.next:
            front = slow
            slow, fast = slow.next, fast.next.next
        fast, front.next = slow.next, None
        root = TreeNode(slow.val)
        if head != slow:
            root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(fast)
        return root