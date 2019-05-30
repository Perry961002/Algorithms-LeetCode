# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # 方法一 使用队列进行层次遍历, 将每一行的最右侧结点放入列表
        res = []
        if root == None:
            return res
        q = [root]
        while q != []:
            curRow = len(q)  # 当前层的结点个数
            while curRow > 0:
                curNode = q.pop(0)
                curRow -= 1
                if curNode.left != None:
                    q.append(curNode.left)
                if curNode.right != None:
                    q.append(curNode.right)
                if curRow == 0:
                    res.append(curNode.val)
        return res