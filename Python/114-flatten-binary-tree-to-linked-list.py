# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        head = root
        while head != None:
            #将右子树接在head的前驱节点后面, 并交换左右子树
            if head.left != None:
                pre = head.left
                #找到前驱节点
                while pre.right != None:
                    pre = pre.right
                #拼接, 并交换
                pre.right = head.right
                head.left, head.right = None, head.left
            head = head.right