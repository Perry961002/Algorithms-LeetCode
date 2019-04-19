# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getPathNum(self, root: TreeNode, num: int) -> int:
        #叶子结点
        if root.left == None and root.right == None:
            return num * 10 + root.val
        #递归
        leftNum, rightNum = 0, 0
        if root.left != None:
            leftNum = self.getPathNum(root.left, num * 10 + root.val)
        if root.right != None:
            rightNum = self.getPathNum(root.right, num * 10 + root.val)
        return leftNum + rightNum
    def sumNumbers(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return self.getPathNum(root, 0)