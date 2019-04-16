# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root == None:
            return res
        queue, isReverse = [root], False
        while queue != []:
            row, size = [], len(queue)
            while size != 0:
                node = queue.pop(0)
                row.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                size -= 1
            if isReverse:
                row.reverse()
            res.append(row)
            isReverse = not isReverse
        return res