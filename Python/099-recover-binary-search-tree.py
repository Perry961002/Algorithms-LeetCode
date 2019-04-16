# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.first, self.second, self.pre = None, None, None
        #中序遍历二叉树，找到递减的节点，如果有一个交换他们相邻的，如果有两个，交换这两个
        def inorder(root: TreeNode) -> None:
            if root == None:
                return None
            if root.left != None:
                inorder(root.left)
            if self.pre != None and self.pre.val > root.val:
                if self.first == None:
                    self.first = self.pre
                self.second = root
            self.pre = root
            if root.right != None:
                inorder(root.right)
        
        if root == None:
            return None
        inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val