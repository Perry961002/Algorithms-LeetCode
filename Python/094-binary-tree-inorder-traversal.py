# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        while root or stack:
            #将所有的子节点入栈
            if root:
                stack.append(root)
                root = root.left
            else:
                #按根-右的顺序访问
                root = stack.pop()
                res.append(root.val)
                root = root.right
        return res