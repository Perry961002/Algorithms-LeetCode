# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isSymmetricTwoTree(p: TreeNode, q: TreeNode) -> bool:
            #都是空
            if p == None and q == None:
                return True
            elif p == None or q == None:
                #有一个为空
                return False
            else:
                #检查两个结点值, 以及左右子树是否对称
                return p.val == q.val and isSymmetricTwoTree(p.left, q.right) and isSymmetricTwoTree(p.right, q.left)
        
        if root == None:
            return True
        return isSymmetricTwoTree(root.left, root.right)