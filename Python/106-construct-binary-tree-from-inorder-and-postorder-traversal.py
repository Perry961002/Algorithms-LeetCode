# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if inorder == []:
            return None
        root = TreeNode(postorder.pop()) #根节点
        index = inorder.index(root.val) #在中序结果中找到根节点的位置
        #递归构造左右子树
        root.left = self.buildTree(inorder[:index], postorder[:index])
        root.right = self.buildTree(inorder[index + 1:], postorder[index:])
        return root