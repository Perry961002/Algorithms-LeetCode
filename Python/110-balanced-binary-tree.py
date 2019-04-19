# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        lDepth = self.getDepth(root.left) #左子树高度
        rDepth = self.getDepth(root.right) #右子树高度
        #左右子树不符合要求, 或者高度差超过1
        if lDepth < 0 or rDepth < 0 or abs(lDepth - rDepth) > 1:
            return -1
        else:
            return max(lDepth, rDepth) + 1
    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True
        lDepth = self.getDepth(root.left) #左子树高度
        rDepth = self.getDepth(root.right) #右子树高度
        #左右子树不符合要求, 或者高度差超过1
        if lDepth < 0 or rDepth < 0 or abs(lDepth - rDepth) > 1:
            return False
        else:
            return True