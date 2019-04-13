# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack = [root]
        res = []
        while stack:
            curNode = stack.pop()
            res.append(curNode.val)
            if curNode.left: stack.append(curNode.left)
            if curNode.right: stack.append(curNode.right)
        res.reverse()
        return res