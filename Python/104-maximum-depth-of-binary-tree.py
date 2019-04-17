# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    """
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
    """
    
    #下面给出bfs的解法
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        depth, q = 0, [root]
        while q != []:
            size = len(q) #当前层的结点数
            while size != 0:
                node = q.pop(0) #取队头元素, 并出队
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                size -= 1
            depth += 1
        return depth