# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        elif root.left == None and root.right == None:
            return 1
        #左右子树不都为空
        lDepth, rDepth = self.minDepth(root.left), self.minDepth(root.right)
        #左右子树有一个不存在
        if not (lDepth and rDepth):
            return lDepth + rDepth + 1
        return min(lDepth, rDepth) + 1