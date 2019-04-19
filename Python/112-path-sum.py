# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root == None:
            return False
        #只有根节点且节点值就等于sum
        if root.left == None and root.right == None and root.val == sum:
            return True
        target = sum - root.val
        #递归判断左右子树
        if self.hasPathSum(root.left, target):
            return True
        if self.hasPathSum(root.right, target):
            return True
        return False