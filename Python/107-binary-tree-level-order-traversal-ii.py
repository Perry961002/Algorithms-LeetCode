# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        res = []
        queue = [root]
        while queue != []:
            row, size = [], len(queue)
            while size != 0:
                node = queue.pop(0)
                row.append(node.val)
                if node.left != None:
                    queue.append(node.left)
                if node.right != None:
                    queue.append(node.right)
                size -= 1
            res.append(row)
        res.reverse()
        return res