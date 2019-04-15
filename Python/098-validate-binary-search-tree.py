# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        """
        这里不能简单地使用递归, 因为要保证节点的左子树只包含小于当前节点的数
        要保证节点的右子树只包含大于当前节点的数
        """
        def inorderTraversal(root: TreeNode) -> List[int]:
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
        TreeList = inorderTraversal(root)
        for i in range(1, len(TreeList)):
            if TreeList[i] <= TreeList[i - 1]:
                return False
        return True